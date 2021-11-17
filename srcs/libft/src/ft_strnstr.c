/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:14 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:14 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*hay_ptr;
	char			*nee_ptr;

	hay_ptr = (char*)haystack;
	nee_ptr = (char*)needle;
	i = 0;
	if (nee_ptr[0] == '\0')
		return (hay_ptr);
	while (hay_ptr[i] && i < len)
	{
		j = 0;
		while (nee_ptr[j] == hay_ptr[i + j] && (i + j) < len)
		{
			if (nee_ptr[j + 1] == '\0')
				return (hay_ptr + i);
			j++;
		}
		if (!hay_ptr[i + 1] && !j)
			return (0);
		i++;
	}
	return (0);
}
