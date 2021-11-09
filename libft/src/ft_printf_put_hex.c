/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_hex.c                                :+:      :+:    :+:   */
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

static unsigned long	ft_printf_get_xlh(va_list arg,
										char lh,
										unsigned char zflag)
{
	if (zflag == 1)
		return (va_arg(arg, size_t));
	else if (lh == 0)
		return (va_arg(arg, unsigned int));
	else if (lh == -2)
		return ((unsigned char)va_arg(arg, unsigned int));
	else if (lh == -1)
		return ((unsigned short)va_arg(arg, unsigned int));
	else if (lh == 1)
		return (va_arg(arg, unsigned long));
	else if (lh == 2)
		return (va_arg(arg, unsigned long));
	return (va_arg(arg, unsigned int));
}

void					ft_printf_put_x(va_list arg, t_printflist *pflist)
{
	unsigned long	x;
	char			*str;

	x = ft_printf_get_xlh(arg, pflist->lh, pflist->zflag);
	pflist->conv = 'd';
	pflist->putlen += ft_uintlen_base(x, FT_MIN_HEX_BASE);
	(pflist->issharp && x != 0) ? (pflist->putlen += 2) : 0;
	(x == 0 && pflist->precision == -1 && pflist->width > 0)
		? (pflist->putlen = 0) : 0;
	ft_printf_put_width_pre(pflist);
	if (pflist->issharp && x != 0)
		ft_printf_cat_output("0x", 2, pflist);
	ft_printf_put_precision(pflist);
	if (!(pflist->precision < 0 && x == 0))
	{
		str = ft_uitoa_base(x, FT_MIN_HEX_BASE);
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	ft_printf_put_width_post(pflist);
}

void					ft_printf_put_big_x(va_list arg, t_printflist *pflist)
{
	unsigned long	x;
	char			*str;

	x = ft_printf_get_xlh(arg, pflist->lh, pflist->zflag);
	pflist->conv = 'd';
	pflist->putlen += ft_uintlen_base(x, FT_MAJ_HEX_BASE);
	(pflist->issharp && x != 0) ? (pflist->putlen += 2) : 0;
	(x == 0 && pflist->precision == -1 && pflist->width > 0)
		? (pflist->putlen = 0) : 0;
	ft_printf_put_width_pre(pflist);
	if (pflist->issharp && x != 0)
		ft_printf_cat_output("0X", 2, pflist);
	ft_printf_put_precision(pflist);
	if (!(pflist->precision < 0 && x == 0))
	{
		str = ft_uitoa_base(x, FT_MAJ_HEX_BASE);
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	ft_printf_put_width_post(pflist);
}
