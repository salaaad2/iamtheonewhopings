/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:12 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:12 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strclen(const char *s, int c)
{
	const char *ptr;

	ptr = s;
	while (ptr != NULL && *ptr != '\0' && *ptr != c)
		ptr++;
	return (ptr - s);
}
