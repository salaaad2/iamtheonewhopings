/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:41 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:41 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	nlst = ft_lstnew((*f)(lst->content));
	if (nlst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		(*del)(lst->content);
		if (!new)
			return (NULL);
		lst = lst->next;
		ft_lstadd_back(&nlst, new);
	}
	return (nlst);
}
