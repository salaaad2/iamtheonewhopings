/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:44 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:44 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_printf_put_c(va_list arg, t_printflist *pflist)
{
	char	c;

	c = va_arg(arg, int);
	pflist->putlen += 1;
	ft_printf_put_width_pre(pflist);
	ft_printf_cat_output(&c, 1, pflist);
	ft_printf_put_width_post(pflist);
}

void	ft_printf_put_perc(va_list arg, t_printflist *pflist)
{
	(void)arg;
	pflist->putlen += 1;
	(pflist->isaz) ? (ft_printf_put_precision(pflist)) : 0;
	ft_printf_put_width_pre(pflist);
	ft_printf_cat_output("%", 1, pflist);
	ft_printf_put_width_post(pflist);
}
