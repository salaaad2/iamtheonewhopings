/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:15 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:15 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*nstr;

	if (!(nstr = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(nstr, s + start, len + 1);
	return (nstr);
}
