/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:09 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:09 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*n_str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s1);
	if ((n_str = (char*)malloc((slen + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		n_str[i] = s1[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
