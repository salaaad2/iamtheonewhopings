/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:27 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:19:29 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	ft_delwords(char **words)
{
	size_t	i;

	i = 0;
	while (words[i] != NULL)
	{
		ft_memdel((void*)&words[i]);
		i++;
	}
	ft_memdel((void*)&words);
}
