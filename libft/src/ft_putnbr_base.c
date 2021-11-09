/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:01 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:01 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_base(long nb, char *base)
{
	long			i;
	unsigned char	size;

	i = nb;
	size = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i >= size)
	{
		ft_putnbr_base(i / size, base);
		ft_putnbr_base(i % size, base);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}
