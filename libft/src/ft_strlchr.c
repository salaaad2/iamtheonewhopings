/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:11 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:11 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

long	ft_strlchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	const size_t	rem = ft_strlen(ft_strchr(s, c));

	if (len - rem >= ft_strlen(s))
		return (-1);
	return (len - rem);
}
