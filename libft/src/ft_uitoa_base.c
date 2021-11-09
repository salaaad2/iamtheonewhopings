/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:19 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:19 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_uitoa_base(unsigned long n, char *base)
{
	char			*s;
	unsigned long	nb;
	unsigned char	i;

	i = ft_uintlen_base(n, base) - 1;
	if (!(s = (char*)malloc((i + 2) * sizeof(char))))
		return (NULL);
	if (n == 0)
		s[i] = '0';
	s[i + 1] = '\0';
	while (n > 0)
	{
		nb = n;
		if (nb >= (unsigned long)ft_strlen(base))
			nb = n % ft_strlen(base);
		s[i] = base[nb];
		n /= ft_strlen(base);
		i--;
	}
	return (s);
}
