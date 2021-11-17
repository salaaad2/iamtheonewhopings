/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:45 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:45 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_printf_get_len(t_printflist *pflist)
{
	int	len;
	int	width;
	int	prec;

	width = pflist->width;
	prec = pflist->precision;
	if (pflist->conv == 'd' && prec > pflist->putlen && !pflist->isneg)
		len = (width - pflist->putlen - (prec - pflist->putlen));
	else if (pflist->conv == 'd' && prec >= pflist->putlen && (pflist->isneg))
		len = (width - pflist->putlen - 1 - (prec - pflist->putlen));
	else if (pflist->conv == 'p' && prec > pflist->putlen)
		len = (width - pflist->putlen - (prec - pflist->putlen + 2));
	else if (pflist->conv == 's' && prec > pflist->putlen && pflist->isaz == 1)
		len = (width - pflist->putlen - (prec - pflist->putlen));
	else
		len = (width - pflist->putlen);
	if (pflist->conv == 'd' && pflist->isaspace == 1 && !pflist->isaplus
		&& (pflist->putlen < 3 && !pflist->isneg))
		len -= 1;
	(len < 0) ? (len = 0) : 0;
	return (len);
}

/*
** Puts the (correct) amount of spaces
** when needed using pflist->width
*/

void		ft_printf_put_width_pre(t_printflist *pflist)
{
	char	*str;

	if (pflist->conv == 'd' && pflist->isaspace == 1 && !pflist->isaplus
		&& (pflist->putlen < 3 && !pflist->isneg))
		ft_printf_cat_output(" ", 1, pflist);
	if (pflist->width - pflist->putlen > 0 && pflist->width - pflist->putlen
			- (pflist->precision - pflist->putlen) >= 0 && !pflist->isreverse)
	{
		if (!(str = malloc((ft_printf_get_len(pflist) + 1) * sizeof(char))))
			return ;
		str = ft_memset(str, ' ', ft_printf_get_len(pflist));
		*(str + ft_printf_get_len(pflist)) = '\0';
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	else if (pflist->conv == 's' && pflist->width - pflist->putlen > 0
		&& !pflist->isreverse)
	{
		if (!(str = malloc((ft_printf_get_len(pflist) + 1) * sizeof(char))))
			return ;
		str = ft_memset(str, ' ', ft_printf_get_len(pflist));
		*(str + ft_printf_get_len(pflist)) = '\0';
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
}

void		ft_printf_put_width_post(t_printflist *pflist)
{
	char	*str;

	if (pflist->width - pflist->putlen > 0 && pflist->width - pflist->putlen
	- (pflist->precision - pflist->putlen) >= 0 && pflist->isreverse)
	{
		if (!(str = (char*)malloc((ft_printf_get_len(pflist) + 1)
			* sizeof(char))))
			return ;
		str = ft_memset(str, ' ', ft_printf_get_len(pflist));
		*(str + ft_printf_get_len(pflist)) = '\0';
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	else if (pflist->conv == 's' && pflist->width - pflist->putlen > 0
		&& pflist->isreverse)
	{
		if (!(str = (char*)malloc((ft_printf_get_len(pflist) + 1)
			* sizeof(char))))
			return ;
		str = ft_memset(str, ' ', ft_printf_get_len(pflist));
		*(str + ft_printf_get_len(pflist)) = '\0';
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
}
