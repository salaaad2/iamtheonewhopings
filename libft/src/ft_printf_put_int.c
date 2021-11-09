/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_int.c                                :+:      :+:    :+:   */
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

static long				ft_printf_get_dlh(va_list arg, char lh)
{
	if (lh == 0)
		return (va_arg(arg, int));
	else if (lh == -2)
		return ((char)va_arg(arg, int));
	else if (lh == -1)
		return ((short)va_arg(arg, int));
	else if (lh == 1)
		return (va_arg(arg, long int));
	else if (lh == 2)
		return (va_arg(arg, long int));
	return (va_arg(arg, int));
}

static unsigned long	ft_printf_get_ulh(va_list arg,
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
		return (va_arg(arg, unsigned long int));
	else if (lh == 2)
		return (va_arg(arg, unsigned long int));
	return (va_arg(arg, unsigned int));
}

static long				ft_printf_put_plus_minus(long d, t_printflist *pflist)
{
	if (pflist->precision >= pflist->putlen && pflist->isneg == 1)
	{
		ft_printf_cat_output("-", 1, pflist);
		pflist->putlen -= 1;
		d = -d;
	}
	else if (pflist->isaplus && !pflist->isneg)
		ft_printf_cat_output("+", 1, pflist);
	return (d);
}

void					ft_printf_put_d(va_list arg, t_printflist *pflist)
{
	char	*str;
	long	d;

	d = ft_printf_get_dlh(arg, pflist->lh);
	(d < 0) ? (pflist->isneg = 1)
		: (pflist->isneg = 0);
	pflist->conv = 'd';
	pflist->putlen += ft_intlen(d);
	if (pflist->isaplus && !pflist->isneg)
		pflist->putlen += 1;
	(d == 0 && pflist->precision == -1 && pflist->width > 0)
		? (pflist->putlen = 0) : 0;
	ft_printf_put_width_pre(pflist);
	d = ft_printf_put_plus_minus(d, pflist);
	ft_printf_put_precision(pflist);
	if (!(pflist->precision < 0 && d == 0))
	{
		str = ft_itoa(d);
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	ft_printf_put_width_post(pflist);
}

void					ft_printf_put_u(va_list arg, t_printflist *pflist)
{
	char			*str;
	unsigned long	d;

	d = ft_printf_get_ulh(arg, pflist->lh, pflist->zflag);
	pflist->conv = 'd';
	pflist->putlen += ft_uintlen(d);
	(d == 0 && pflist->precision == -1 && pflist->width > 0)
		? (pflist->putlen = 0) : 0;
	ft_printf_put_width_pre(pflist);
	ft_printf_put_precision(pflist);
	if (!(pflist->precision < 0 && d == 0))
	{
		str = ft_uitoa(d);
		ft_printf_cat_output(str, ft_strlen(str), pflist);
		ft_memdel((void**)&str);
	}
	ft_printf_put_width_post(pflist);
}
