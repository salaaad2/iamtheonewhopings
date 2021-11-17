/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:18 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:18 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_uitoa(unsigned long n)
{
	char			*s;
	unsigned long	nb;
	unsigned char	i;

	i = ft_uintlen(n) - 1;
	if (!(s = (char*)malloc((i + 2) * sizeof(char))))
		return (NULL);
	if (n == 0)
		s[i] = '0';
	nb = n;
	s[i + 1] = '\0';
	while (nb > 0)
	{
		s[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (s);
}
