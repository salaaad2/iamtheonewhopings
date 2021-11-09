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

#include "u_lstcont.h"
#include "l_main.h"
#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

void	l_lstdelone(t_elem *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

void	l_lstclear(t_elem **lst, void (*del)(void *))
{
	t_elem	*tmp;
	t_elem	*renext;

	if (lst == NULL)
	{
		return ;
	}
	tmp = *lst;
	while (tmp != NULL)
	{
		renext = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = renext;
	}
	*lst = NULL;
}

void	l_lstadd_front(t_elem **alst, t_elem *new)
{
	if (alst == NULL || new == NULL)
	{
		return ;
	}
	new->next = *alst;
	*alst = new;
}

void	l_lstadd_back(t_elem **alst, t_elem *new)
{
	t_elem	*tmp;

	if (alst == NULL || new == NULL)
	{
		return ;
	}
	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		tmp = l_lstlast(*alst);
		tmp->next = new;
	}
}

t_elem	*l_lstnew(void *content)
{
	t_elem	*nlst;

	nlst = (t_elem*)ft_calloc(1, sizeof(t_elem));
	if (nlst == NULL)
	{
		return (NULL);
	}
	nlst->content = content;
	nlst->next = NULL;
	return (nlst);
}
