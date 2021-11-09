/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_precision.c                          :+:      :+:    :+:   */
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
	if (pflist->conv == 'p' && pflist->precision > pflist->putlen)
		return (pflist->precision - pflist->putlen + 2);
	else if (pflist->precision > pflist->putlen && pflist->isneg == 0
			&& pflist->isaplus == 0)
		return (pflist->precision - pflist->putlen);
	else if (pflist->precision >= pflist->putlen && pflist->isneg == 1)
	{
		if (pflist->isaz == 1)
			return (pflist->precision - pflist->putlen - 1);
		else
			return (pflist->precision - pflist->putlen);
	}
	else if (pflist->precision >= pflist->putlen && pflist->isneg == 0
			&& pflist->isaplus == 1)
	{
		if (pflist->isaz == 1)
			return (pflist->precision - pflist->putlen);
		else
			return (pflist->precision - pflist->putlen + 1);
	}
	return (0);
}

/*
** Puts the correct amount of 0's when
** needed using pflist->precision.
** Used for %p, %d, %i, %u, %x and %X
*/

int			ft_printf_put_precision(t_printflist *pflist)
{
	char	*str;
	int		len;

	len = 0;
	if (pflist->precision >= pflist->putlen)
	{
		len = ft_printf_get_len(pflist);
		if (!(str = (char*)malloc((len + 1) * sizeof(char))))
			return (1);
		str = ft_memset(str, '0', len);
		*(str + len) = '\0';
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	return (0);
}
