/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_none.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:45 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:45 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printf_put_none(t_printflist *pflist)
{
	ft_printf_put_width_pre(pflist);
	ft_printf_put_width_post(pflist);
}
