/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_ptr.c                                :+:      :+:    :+:   */
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

/*
** For GCC: if (!p) { ft_putstr("(nil)"); return ; }
*/

void	ft_printf_put_p(va_list arg, t_printflist *pflist)
{
	unsigned long	p;
	char			*str;

	p = va_arg(arg, unsigned long);
	pflist->conv = 'p';
	pflist->putlen += 2 + ft_uintlen_base(p, FT_MIN_HEX_BASE);
	ft_printf_put_width_pre(pflist);
	ft_printf_cat_output("0x", 2, pflist);
	if (pflist->precision > pflist->putlen - 2)
		ft_printf_put_precision(pflist);
	if (!(pflist->precision < 0 && p == 0))
	{
		str = ft_uitoa_base(p, FT_MIN_HEX_BASE);
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	ft_printf_put_width_post(pflist);
}
