/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process.c                                :+:      :+:    :+:   */
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
#include <limits.h>

/*
** calls the corresponding function to
** the right conv using:
** FT_PRINTF_CONV_CHARSET "cspdiuxX%"
*/

void	ft_printf_process(const char *format, va_list arg, t_printflist *pflist)
{
	int		conv;
	void	(*fun_ptr[9])(va_list, t_printflist *);

	fun_ptr[0] = ft_printf_put_c;
	fun_ptr[1] = ft_printf_put_s;
	fun_ptr[2] = ft_printf_put_p;
	fun_ptr[3] = ft_printf_put_d;
	fun_ptr[4] = ft_printf_put_d;
	fun_ptr[5] = ft_printf_put_u;
	fun_ptr[6] = ft_printf_put_x;
	fun_ptr[7] = ft_printf_put_big_x;
	fun_ptr[8] = ft_printf_put_perc;
	if ((conv = ft_strlchr(FT_PRINTF_CONV_CHARSET,
				*(format + pflist->flaglen + 1))) >= 0)
		(*fun_ptr[conv])(arg, pflist);
	else
		ft_printf_put_none(pflist);
}
