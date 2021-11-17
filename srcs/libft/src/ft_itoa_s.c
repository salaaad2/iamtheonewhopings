/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:40 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:40 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_itoa_s(char str[], long n)
{
	long			nb;
	unsigned char	i;

	i = ft_intlen(n) - 1;
	if (n == 0)
		str[i] = '0';
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
}
