/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:43 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:43 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_nrealloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*nptr;

	if (ptr == NULL && newsize > 0)
	{
		if ((ptr = malloc(newsize)) == NULL)
		{
			return (NULL);
		}
		return (ptr);
	}
	else if (newsize == 0)
	{
		ft_memdel((void*)&ptr);
		return (NULL);
	}
	if ((nptr = malloc(newsize)) == NULL)
	{
		return (ptr);
	}
	(void)ft_memcpy(nptr, ptr, oldsize);
	ft_memdel((void*)&ptr);
	return (nptr);
}
