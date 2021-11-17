/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:40 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:40 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_itoa_base(long n, char *base)
{
	char			*s;
	long			nb;
	unsigned char	i;

	i = ft_intlen_base(n, base) - 1;
	if ((s = (char*)malloc((i + 2) * sizeof(char))) == NULL)
		return (NULL);
	if (n == 0)
		s[i] = '0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -n;
	}
	s[i + 1] = '\0';
	while (n > 0)
	{
		nb = n;
		if (nb >= (long)ft_strlen(base))
			nb = n % ft_strlen(base);
		s[i] = base[nb];
		n /= ft_strlen(base);
		i--;
	}
	return (s);
}
