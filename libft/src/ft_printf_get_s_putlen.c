/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_s_putlen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:43 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:43 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf_get_s_putlen(char *str, t_printflist *pflist)
{
	int	ret;

	if (pflist->precision > 0
		&& (int)ft_strlen((const char*)str) > pflist->precision)
		ret = pflist->precision;
	else if (pflist->precision == -1)
		ret = 0;
	else
		ret = ft_strlen((const char*)str);
	return (ret);
}
