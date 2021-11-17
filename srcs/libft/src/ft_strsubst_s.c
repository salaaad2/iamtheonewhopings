/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubst_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:27 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:19:29 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	ft_strsubst_s(char *str, const char *pattern, const char *subst)
{
	char	*ptr;

	if ((ptr = ft_strnstr(str, pattern, ft_strlen(str))) == NULL)
		return (1);
	(void)ft_memmove(str + ((ptr - str) + ft_strlen(subst)),
		str + ((ptr - str) + ft_strlen(pattern)),
		(ft_strlen(str + ((ptr - str) + ft_strlen(pattern))) + 1)
		* sizeof(char));
	(void)ft_memmove(str + (ptr - str),
		subst,
		ft_strlen(subst) * sizeof(char));
	return (0);
}
