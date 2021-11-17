/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parts.c                                  :+:      :+:    :+:   */
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

int	ft_printf_get_partlen(const char *format)
{
	int	ret;

	ret = ft_strlchr(format, '%');
	if (ret < 0)
		return (ft_strlen(format));
	else
		return (ret);
}

int	ft_printf_putpart(const char *format,
					int start,
					int len,
					t_printflist *pflist)
{
	char	*nstr;
	int		ret;

	ft_printf_cat_output(nstr = ft_substr(format, start, len), len, pflist);
	ft_memdel((void**)&nstr);
	ret = 0;
	return (ret);
}
