/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:06 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:06 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static int	ft_printf_return(char *str, t_printflist *pflist)
{
	int	ret;

	ft_strlcpy(str, pflist->output, pflist->fulllen + 1);
	ret = pflist->fulllen;
	ft_memdel((void**)&pflist->output);
	ft_memdel((void**)&pflist->fullflag);
	ft_memdel((void**)&pflist);
	return (ret);
}

int			ft_sprintf(char *str, const char *format, ...)
{
	t_printflist	*pflist;
	va_list			arg;
	int				pos;

	if (!format)
		return (-1);
	if ((pos = ft_strlchr(format, '%')) < 0)
		return (ft_strlcpy(str, format, ft_strlen(format) + 1));
	else
	{
		pflist = ft_printf_init_struct(format);
		ft_printf_putpart(format, 0, pos, pflist);
		va_start(arg, format);
		while (pos >= 0)
		{
			pos = ft_printf_flags(format, pos, arg, pflist);
			ft_printf_reinit_struct(pflist);
		}
		va_end(arg);
		return (ft_printf_return(str, pflist));
	}
	return (0);
}
