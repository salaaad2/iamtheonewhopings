/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:27 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:19:29 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strsubst(char *str, const char *pattern, const char *subst)
{
	size_t	nlen;
	char	*nstr;
	char	*ptr;

	if ((ptr = ft_strnstr(str, pattern, ft_strlen(str))) == NULL)
		return (NULL);
	nlen = ft_strlen(str) - ft_strlen(pattern) + ft_strlen(subst);
	if ((nstr = (char*)malloc((nlen + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(nstr, str, ptr - str);
	ft_memcpy(nstr + (ptr - str), subst, ft_strlen(subst));
	ft_memcpy(nstr + (ptr - str + ft_strlen(subst)),
		str + (ptr - str + ft_strlen(pattern)),
		ft_strlen(str + (ptr - str + ft_strlen(pattern))));
	nstr[nlen] = '\0';
	ft_memdel((void*)&str);
	return (nstr);
}
