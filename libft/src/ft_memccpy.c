/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:41 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:41 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (*dst_ptr == '\0' && *src_ptr == '\0' && n != 0)
		return (NULL);
	if (n != 0)
	{
		while (n != 0)
		{
			if ((*dst_ptr++ = *src_ptr++) == (unsigned char)c)
				return (dst_ptr);
			n--;
		}
	}
	return (NULL);
}
