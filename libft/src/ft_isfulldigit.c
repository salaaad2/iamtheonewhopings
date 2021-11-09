/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:39 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:39 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool	ft_isfulldigit(char *str)
{
	unsigned int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i == ft_strlen(str));
}
