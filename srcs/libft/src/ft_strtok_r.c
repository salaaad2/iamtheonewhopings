/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:12 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:12 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_stok	ft_cont(char *s, const char *delim)
{
	t_stok	stok;
	t_bool	inc;

	stok.c = *s++;
	stok.spanp = (char *)delim;
	inc = TRUE;
	while ((stok.sc = *stok.spanp) != '\0')
	{
		if (stok.c == stok.sc)
		{
			stok.c = *s++;
			stok.spanp = (char*)delim;
			inc = FALSE;
		}
		if (inc == TRUE)
			stok.spanp++;
		else
			inc = TRUE;
	}
	stok.ns = s;
	return (stok);
}

static char		*ft_scan_ret(char *s, char **last, char *tok, t_stok stok)
{
	if ((stok.sc = *stok.spanp++) == stok.c)
	{
		if (stok.c == '\0')
			s = NULL;
		else
			s[-1] = '\0';
		*last = s;
		return (tok);
	}
	while (stok.sc != '\0')
	{
		if ((stok.sc = *stok.spanp++) == stok.c)
		{
			if (stok.c == '\0')
				s = NULL;
			else
				s[-1] = '\0';
			*last = s;
			return (tok);
		}
	}
	return (NULL);
}

static char		*ft_scan_tok(char *s,
							const char *delim,
							char **last,
							t_stok stok)
{
	char	*tok;
	char	*ret;

	tok = s - 1;
	while (TRUE)
	{
		stok.c = *s++;
		stok.spanp = (char *)delim;
		if ((ret = ft_scan_ret(s, last, tok, stok)) != NULL)
		{
			return (ret);
		}
	}
}

char			*ft_strtok_r(char *s, const char *delim, char **last)
{
	t_stok	stok;

	if (s == NULL && (s = *last) == NULL)
		return (NULL);
	stok = ft_cont(s, delim);
	s = stok.ns;
	if (stok.c == '\0')
		*last = NULL;
	if (stok.c == '\0')
		return (NULL);
	return (ft_scan_tok(s, delim, last, stok));
}
