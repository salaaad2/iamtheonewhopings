/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:42 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:42 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

long	ft_memlchr(const void *s, int c, size_t n)
{
	const size_t len = ft_strlen((const char *)s);
	const size_t rem = ft_strlen((const char *)ft_memchr(s, c, n));

	if (len - rem >= ft_strlen((const char *)s))
		return (-1);
	return (len - rem);
}
