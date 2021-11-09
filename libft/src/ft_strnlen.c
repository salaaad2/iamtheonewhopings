/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:14 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:14 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *s, size_t size)
{
	const char *ptr = s;

	while (size > 0 && *ptr != '\0')
	{
		size--;
		ptr++;
	}
	return (ptr - s);
}
