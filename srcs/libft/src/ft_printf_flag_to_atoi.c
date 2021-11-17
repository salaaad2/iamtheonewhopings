/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_to_atoi.c                           :+:      :+:    :+:   */
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

char	*ft_printf_flag_to_atoi(char *str)
{
	char	*nstr;
	char	*nnstr;
	int		len;

	while (*str != '.' && *str != '\0')
		str++;
	while (*str != '-' && *str != '\0')
		str--;
	len = ft_strlchr(str, ' ');
	nnstr = ft_substr(str, 0, len);
	nstr = ft_strjoin(nnstr, str + len + 1);
	ft_memdel((void**)&nnstr);
	return (nstr);
}
