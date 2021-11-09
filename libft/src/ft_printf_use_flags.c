/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_use_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:45 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:45 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	ft_printf_noflags(const char *format,
							int pos,
							va_list arg,
							t_printflist *pflist)
{
	ft_printf_process(format + pos, arg, pflist);
}

static void	ft_printf_withflags(const char *format,
								int pos,
								va_list arg,
								t_printflist *pflist)
{
	ft_memdel((void**)&pflist->fullflag);
	pflist->fullflag = ft_printf_get_flags(format, pos, pflist);
	ft_printf_treat_flags(arg, pflist);
	ft_printf_process(format + pos, arg, pflist);
}

int			ft_printf_flags(const char *format,
							int pos,
							va_list arg,
							t_printflist *pflist)
{
	int	plen;

	plen = 0;
	if (ft_ischarset(FT_PRINTF_CONV_CHARSET, *(format + pos + 1)))
	{
		ft_printf_noflags(format, pos, arg, pflist);
		plen = ft_printf_get_partlen(format + pos + 2);
		ft_printf_putpart(format, pos + 2, plen, pflist);
		if (plen == (int)ft_strlen(format + pos + 2))
			return (-1);
		else
			return (pos + plen + 2);
	}
	else
	{
		ft_printf_withflags(format, pos, arg, pflist);
		plen = ft_printf_get_partlen(format + pos + pflist->flaglen + 2);
		ft_printf_putpart(format, pos + pflist->flaglen + 2,
							plen, pflist);
		if (plen == (int)ft_strlen(format + pos + pflist->flaglen + 2))
			return (-1);
		else
			return (pos + plen + pflist->flaglen + 2);
	}
}
