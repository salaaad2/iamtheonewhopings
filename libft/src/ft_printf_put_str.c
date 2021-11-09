/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_str.c                                :+:      :+:    :+:   */
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

void	ft_printf_put_s(va_list arg, t_printflist *pflist)
{
	char	*str;
	char	*nstr;

	pflist->conv = 's';
	str = va_arg(arg, char*);
	if (!str)
		str = "(null)";
	pflist->putlen += ft_printf_get_s_putlen(str, pflist);
	ft_printf_put_width_pre(pflist);
	if ((int)ft_strlen(str) > pflist->putlen)
	{
		ft_printf_cat_output(nstr = ft_substr(str, 0, pflist->putlen),
							pflist->putlen, pflist);
		ft_memdel((void**)&nstr);
	}
	else
		ft_printf_cat_output(str, pflist->putlen, pflist);
	ft_printf_put_width_post(pflist);
}
