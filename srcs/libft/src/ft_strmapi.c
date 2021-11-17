/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:13 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:13 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!s)
		return (NULL);
	i = 0;
	nstr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (nstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		nstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (nstr);
}
