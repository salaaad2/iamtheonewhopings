/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cat_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:43 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:43 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <unistd.h>

void	ft_printf_cat_output(char *src, size_t len, t_printflist *pflist)
{
	size_t	dst_len;

	dst_len = pflist->fulllen;
	pflist->output = (char*)ft_nrealloc(pflist->output,
		(dst_len + 1) * sizeof(char),
		(dst_len + len + 1) * sizeof(char));
	(void)ft_memcpy(pflist->output + dst_len, src, len * sizeof(char));
	*(pflist->output + dst_len + len) = '\0';
	pflist->fulllen += len;
}
