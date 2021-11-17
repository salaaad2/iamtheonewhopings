/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:39 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:39 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

t_bool	ft_ischarset(const char *charset, int c)
{
	size_t	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
		{
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
