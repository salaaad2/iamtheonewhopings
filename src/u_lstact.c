/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:06:41 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:06:41 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "p_main.h"
#include <libft.h>
#include <stddef.h>
#include "u_lstact.h"

int
l_lstsize(t_elem *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_elem	*
l_lstmap(t_elem *lst, void *(*f)(void *), void (*del)(void *))
{
	t_elem	*nlst;
	t_elem	*new;

	if (lst == NULL)
		return (NULL);
	nlst = l_lstnew((*f)(lst->content));
	if (nlst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new = l_lstnew((*f)(lst->content));
		(*del)(lst->content);
		if (!new)
			return (NULL);
		lst = lst->next;
		l_lstadd_back(&nlst, new);
	}
	return (nlst);
}

t_elem	*
l_lstlast(t_elem *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void
l_lstiter(t_elem *lst, void (*f)(void *))
{
	if (lst == NULL)
	{
		return ;
	}
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

int
l_lstswap(t_elem * one, t_elem * two)
{
	one->next = two->next;
	two->next = one;
	return (0);
}
