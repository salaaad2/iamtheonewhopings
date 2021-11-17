/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:18 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:18 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_uitoa_s(char str[], unsigned long n)
{
	unsigned long	nb;
	unsigned char	i;

	i = ft_uintlen(n) - 1;
	if (n == 0)
		str[i] = '0';
	nb = n;
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
}
