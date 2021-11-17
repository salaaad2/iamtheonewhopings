/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:22 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:24 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char				ft_setsign(const char c)
{
	char	sign;

	sign = 1;
	if (c == '-')
	{
		sign = -1;
	}
	return (sign);
}

static unsigned char	ft_seti(const char *str)
{
	unsigned char	i;

	i = 0;
	while (ft_isspace(str[i]) == TRUE)
	{
		i++;
	}
	return (i);
}

int						ft_atoi(const char *str)
{
	long			nb;
	unsigned char	i;
	char			sign;

	i = ft_seti(str);
	nb = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = ft_setsign(str[i++]);
	while (str[i] != '\0' && ft_isdigit(str[i]) == TRUE)
	{
		if (nb * 10 + (str[i] - 48) < nb)
		{
			if (sign < 0)
			{
				return (0);
			}
			return (-1);
		}
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb *= sign;
	return ((int)nb);
}
