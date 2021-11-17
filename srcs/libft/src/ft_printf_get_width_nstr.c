/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_width_nstr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:44 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:44 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf_fetch_width(va_list arg, char *nstr, t_printflist *pflist)
{
	int		ret;
	char	*str;

	if (ft_strlchr(nstr, '*') >= 0)
	{
		(ft_strlchr(pflist->fullflag, '-') >= 0) ? (pflist->isminus = 1) : 0;
		(pflist->isminus) ? (pflist->isreverse = 1) : 0;
		ret = va_arg(arg, int);
	}
	else if ((pflist->isaspace = ft_strlchr(pflist->fullflag, ' ')) >= 0)
	{
		str = ft_printf_flag_to_atoi(pflist->fullflag);
		ret = ft_atoi(str);
		ft_memdel((void**)&str);
	}
	else
	{
		if (*nstr == '-' && ft_strlen(nstr) >= 2)
		{
			nstr += 1;
			pflist->isreverse = 1;
		}
		ret = ft_atoi(nstr);
	}
	return (ret);
}

char	*ft_printf_get_width_nstr(char *str, t_printflist *pflist)
{
	(ft_strlchr(pflist->fullflag, '+') >= 0) ? (pflist->isaplus = 1) : 0;
	(*(pflist->fullflag) == '+' && *(pflist->fullflag + 1)) ? (str += 1) : 0;
	(*(pflist->fullflag) == '0' && *(pflist->fullflag + 1)) ? (str += 1) : 0;
	(*(pflist->fullflag) == '#' && *(pflist->fullflag + 1)
		&& (pflist->actconv == 'x' || pflist->actconv == 'X')) ? (str += 1) : 0;
	return (str);
}
