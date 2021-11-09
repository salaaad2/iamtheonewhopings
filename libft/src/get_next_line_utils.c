/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:20 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:20 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen_gnl(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

int		ft_free_gnl(int fd, t_gnl **list)
{
	t_gnl	*scout;
	t_gnl	*prev;

	prev = *list;
	if (prev->fd == fd)
	{
		scout = prev->next;
		ft_memdel((void*)&prev->rest);
		ft_memdel((void*)&prev);
		*list = scout;
		return (0);
	}
	scout = prev->next;
	while (scout->fd != fd)
	{
		prev = prev->next;
		scout = scout->next;
	}
	prev->next = scout->next;
	ft_memdel((void*)&scout->rest);
	ft_memdel((void*)&scout);
	return (0);
}

t_gnl	*ft_find_fd(int fd, t_gnl **list)
{
	t_gnl	*curr;
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->rest = 0;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return (*list);
	}
	curr = *list;
	if (fd != curr->fd)
	{
		while (curr->next != NULL && fd != curr->fd)
			curr = curr->next;
		if (curr->next == NULL)
			return (curr->next = new);
	}
	ft_memdel((void*)&new);
	return (curr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	c = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != 0 && s[i] != c)
		i++;
	if (s[i] != c)
		return (NULL);
	return ((char *)s + i);
}

char	*ft_swap_gnl(char *s1, char *free_ft)
{
	char	*dst;
	int		i;

	if (!(dst = (char*)malloc((ft_strlen_gnl(s1, 0) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	ft_memdel((void*)&free_ft);
	return (dst);
}
