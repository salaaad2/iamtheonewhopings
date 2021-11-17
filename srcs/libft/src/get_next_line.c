/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
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
#include <unistd.h>

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;
	size_t	size1;
	size_t	size2;

	i = -1;
	j = -1;
	size1 = ft_strlen_gnl(s1, 10);
	size2 = ft_strlen_gnl(s2, 10);
	if (!(dst = (char*)malloc((size1 + size2 + 1) * sizeof(char))))
		return (NULL);
	while (++i < size1)
		dst[i] = s1[i];
	while (++j < size2)
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	ft_memdel((void*)&s1);
	return (dst);
}

static int	ft_read_gnl(int fd, char **line, t_gnl *curr)
{
	char	*buf;
	char	*end;
	long	size;

	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	*buf = 0;
	*line = ft_strjoin_gnl(*line, curr->rest);
	size = BUFFER_SIZE;
	while ((end = ft_strchr_gnl(buf, 10)) == NULL && size == BUFFER_SIZE)
	{
		*line = ft_strjoin_gnl(*line, buf);
		if ((size = read(fd, buf, BUFFER_SIZE)) == -1)
			ft_memdel((void*)&buf);
		if (size == -1)
			return (-1);
		buf[size] = 0;
	}
	*line = ft_strjoin_gnl(*line, buf);
	if (end)
		curr->rest = ft_swap_gnl(end + 1, curr->rest);
	ft_memdel((void*)&buf);
	if (!end)
		return (0);
	return (size);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*curr;
	char			*end;
	int				size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((*line = (char *)malloc(1 * sizeof(char))) == NULL)
		return (-1);
	**line = 0;
	curr = ft_find_fd(fd, &list);
	if (ft_strchr_gnl(curr->rest, 10) == NULL)
		size = ft_read_gnl(fd, line, curr);
	else
	{
		end = ft_strchr_gnl(curr->rest, 10);
		*line = ft_strjoin_gnl(*line, curr->rest);
		curr->rest = ft_swap_gnl(end + 1, curr->rest);
		size = 1;
	}
	if (size > 0)
		return (1);
	ft_free_gnl(fd, &list);
	return ((size == -1) ? -1 : 0);
}
