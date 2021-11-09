/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_treat_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:45 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:45 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdarg.h>

static int				ft_printf_get_width(va_list arg, t_printflist *pflist)
{
	char	*nstr;
	char	*nstr_ptr;
	int		ret;

	if (ft_strlchr(pflist->fullflag, '.') >= 0)
		nstr = ft_substr(pflist->fullflag, 0,
						ft_strlchr(pflist->fullflag, '.'));
	else
		nstr = ft_strdup(pflist->fullflag);
	nstr_ptr = nstr;
	nstr = ft_printf_get_width_nstr(nstr, pflist);
	ret = ft_printf_fetch_width(arg, nstr, pflist);
	ft_memdel((void**)&nstr_ptr);
	(ret < 0) ? (pflist->isreverse = 1) : 0;
	(ret < 0) ? (ret = -ret) : 0;
	return (ret);
}

static int				ft_printf_get_precision(va_list arg,
												int pos,
												t_printflist *pflist)
{
	int		ret;
	char	*ptr;

	ptr = pflist->fullflag;
	if (pflist->isaz && ft_strlchr(pflist->fullflag, '+') >= 0)
	{
		pflist->isaplus = 1;
		if (ft_strlen(ptr) < pflist->flaglen)
			ptr += 1;
	}
	if (*(ptr + pos + 1) == '*')
	{
		ret = va_arg(arg, int);
		(ret < 0) ? (ret = 0) : 0;
		return (ret);
	}
	else
		ret = ft_atoi(ptr + pos + 1);
	if (ret == 0)
		return (-1);
	return (ret);
}

/*
** Corresponding l ll hh h
** in pflist->lh
** hh = -2
** h = -1
** l = 1
** ll = 2
*/

static void				ft_printf_get_lh(t_printflist *pflist)
{
	int	pos;

	if ((pos = ft_strlchr(pflist->fullflag, 'z')) >= 0)
		pflist->zflag = 1;
	else if ((pos = ft_strlchr(pflist->fullflag, 'l')) >= 0)
	{
		if (pos + 2 <= (int)pflist->flaglen &&
			*(pflist->fullflag + pos + 1) == 'l')
			pflist->lh = 2;
		else
			pflist->lh = 1;
	}
	else if ((pos = ft_strlchr(pflist->fullflag, 'h')) >= 0)
	{
		if (pos + 2 <= (int)pflist->flaglen &&
			*(pflist->fullflag + pos + 1) == 'h')
			pflist->lh = -2;
		else
			pflist->lh = -1;
	}
}

static unsigned char	ft_printf_check_z(t_printflist *pflist)
{
	char	*ptr;

	ptr = pflist->fullflag;
	while (!ft_isdigit(*ptr) && *ptr)
		ptr++;
	if ((ptr - pflist->fullflag) <= (long)ft_strlen(pflist->fullflag)
		&& (*ptr == '0') && ft_strlchr(pflist->fullflag, '.') < 0)
		return (1);
	return (0);
}

/*
** Uses pflist->fullflag to put
** width and precision in the list
** also l ll hh h
*/

void					ft_printf_treat_flags(va_list arg, t_printflist *pflist)
{
	int		pos;
	char	c;

	pflist->flaglen = ft_strlen(pflist->fullflag);
	if (((pflist->isaz = ft_printf_check_z(pflist)) == 1
		&& ft_strlchr(pflist->fullflag, '.') < 0
		&& ft_strlchr(pflist->fullflag, '-') < 0))
		pflist->precision = ft_printf_get_precision(arg, 0, pflist);
	else
	{
		pflist->width = ft_printf_get_width(arg, pflist);
		(pflist->isaspace >= 0) ? (pflist->isaspace = 1) : 0;
		if ((pos = ft_strlchr(pflist->fullflag, '.')) >= 0)
			pflist->precision = ft_printf_get_precision(arg, pos, pflist);
	}
	(pflist->isaz && pflist->width) ? (pflist->isaz = 0) : 0;
	(ft_strlchr(pflist->fullflag, '#') >= 0) ? (pflist->issharp = 1) : 0;
	c = pflist->actconv;
	if (ft_strlchr(pflist->fullflag, '.') < 0 && pflist->isaz
	&& pflist->precision < 0 && c != 'c' && c != 's' && c != '%')
	{
		pflist->precision = 0;
		pflist->isaz = 0;
	}
	ft_printf_get_lh(pflist);
}
