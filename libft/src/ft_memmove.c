/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:42 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:42 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*from = (const char*)src;
	char		*to;
	int			i;
	size_t		j;

	to = (char*)dst;
	if (to > from && to - from < (int)len)
	{
		i = len;
		while (--i >= 0)
			to[i] = from[i];
		return (dst);
	}
	if (from > to && from - to < (int)len)
	{
		j = -1;
		while (++j < len)
			to[j] = from[j];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
