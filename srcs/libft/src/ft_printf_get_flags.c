/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flags.c                              :+:      :+:    :+:   */
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

/*
** Copies everything between '%' and any
** FT_PRINTF_CONV_CHARSET "cspdiuxX%"
** into the fullflag string and returns it.
** Also puts actual conv into pflist->actconv
*/

char	*ft_printf_get_flags(const char *format, int pos, t_printflist *pflist)
{
	int		i;
	char	*nstr;
	char	*fullflag;

	i = 0;
	while (!ft_ischarset(FT_PRINTF_CONV_CHARSET, *(format + pos + i + 1))
			&& *(format + pos + i + 1))
		i++;
	if ((fullflag = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(fullflag, nstr = ft_substr(format, pos + 1, i), i);
	ft_memdel((void**)&nstr);
	fullflag[i] = '\0';
	pflist->actconv = *(format + pos + i + 1);
	return (fullflag);
}
