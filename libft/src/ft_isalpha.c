/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:39 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:39 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_isalpha(int c)
{
	if (ft_isupper(c) == TRUE || ft_islower(c) == TRUE)
	{
		return (TRUE);
	}
	return (FALSE);
}
