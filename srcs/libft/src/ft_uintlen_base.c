/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:17 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:17 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned char	ft_uintlen_base(unsigned long n, char *base)
{
	unsigned char	len;
	unsigned char	size;

	size = ft_strlen(base);
	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= size;
		len++;
	}
	return (len);
}
