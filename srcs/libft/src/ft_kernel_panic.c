/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kernel_panic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:40 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:40 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_kernel_panic(void)
{
	int	*ptr;

	while (1)
	{
		ptr = (int *)ft_calloc((1024 * 1024) * sizeof(int), 1);
	}
	free(ptr);
}
