/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:44 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:44 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

t_printflist	*ft_printf_init_struct(const char *format)
{
	t_printflist	*pflist;

	(void)format;
	if (!(pflist = (t_printflist*)malloc(sizeof(t_printflist))))
		return (NULL);
	if (!(pflist->fullflag = (char *)ft_calloc(1, sizeof(char))))
		return (NULL);
	ft_printf_reinit_struct(pflist);
	pflist->fulllen = 0;
	if (!(pflist->output = (char*)ft_calloc(1, sizeof(char))))
		return (NULL);
	return (pflist);
}

void			ft_printf_reinit_struct(t_printflist *pflist)
{
	pflist->conv = 0;
	pflist->actconv = 0;
	pflist->flaglen = 0;
	pflist->width = 0;
	pflist->precision = 0;
	pflist->isreverse = 0;
	pflist->isneg = 0;
	pflist->isaz = 0;
	pflist->isaspace = -1;
	pflist->isaplus = 0;
	pflist->putlen = 0;
	pflist->lh = 0;
	pflist->zflag = 0;
	pflist->issharp = 0;
	pflist->isminus = 0;
}
