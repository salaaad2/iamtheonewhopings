/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:41 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:41 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*nlst;

	nlst = (t_list*)ft_calloc(1, sizeof(t_list));
	if (nlst == NULL)
	{
		return (NULL);
	}
	nlst->content = content;
	nlst->next = NULL;
	return (nlst);
}
