/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:39 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:39 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static int	ft_printf_return(int fd, t_printflist *pflist)
{
	int	ret;

	ret = write(fd, pflist->output, pflist->fulllen);
	ft_memdel((void**)&pflist->output);
	ft_memdel((void**)&pflist->fullflag);
	ft_memdel((void**)&pflist);
	return (ret);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_printflist	*pflist;
	va_list			arg;
	int				pos;

	if (!format)
		return (-1);
	if ((pos = ft_strlchr(format, '%')) < 0)
		return (write(fd, format, ft_strlen(format)));
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
		return (ft_printf_return(fd, pflist));
	}
	return (0);
}
