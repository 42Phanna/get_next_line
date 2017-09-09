/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/09/09 17:04:59 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_box	*fd_select(const int fd, t_box **first)
{
	t_box	*bro_tips;

	if (!(*first))
	{
		if (!((*first) = (t_box *)malloc(sizeof(t_box))))
			exit(EXIT_FAILURE);
		(*first)->buff = NULL;
		(*first)->fd = (int)fd;
		(*first)->next = NULL;
		return (*first);
	}
	bro_tips = *first;
	while (bro_tips->next && bro_tips->fd != fd)
		bro_tips = bro_tips->next;
	if (bro_tips->fd != fd)
	{
		if (!(bro_tips = (t_box *)malloc(sizeof(t_box))))
			exit(EXIT_FAILURE);
		bro_tips->buff = NULL;
		bro_tips->fd = (int)fd;
		bro_tips->next = *first;
		*first = bro_tips;
		return (*first);
	}
	return (bro_tips);
}

char			*ft_strcdup(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		++i;
	if (src[i] == c)
	{
		if (!(dst = ft_memalloc(i + 1)))
			return (0);
		dst = ft_strncpy(dst, src, i + 1);
		return (dst);
	}
	return (0);
}

int				ft_found_eol(t_box *box, char **line)
{
	ft_putendl("IN_FOUND");
	if (!box->buff || !(ft_strchr(box->buff, '\n')))
	{
		ft_putendl("NOT_FOUND");
		return (0);
	}
	*line = ft_strcdup(*line, box->buff, '\n');
	box->buff = ft_strchr(box->buff, '\n');
	++box->buff;
	return (1);
}

int				gnl_read(t_box *box, char **line)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	ft_putendl("IN_GNL_READ");
	if (ft_found_eol(box, line))
		return (1);
	ft_putendl("FIRST_TEST_NOT_FOUND");
	tmp = NULL;
	while ((ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		ft_putendl(box->buff);
		tmp = box->buff;
		if (!box->buff)
			box->buff = buffer;
		else
			box->buff = ft_strjoin(box->buff, buffer);
		ft_putendl(box->buff);
		free(tmp);
		if (ft_found_eol(box, line))
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_box	*first = NULL;
	t_box			*box;
	int				res;

	box = fd_select(fd, &first);
	ft_putendl("FT_SELECT_OK");
	if (fd < 0 || !line || !box)
		return (-1);
	res = gnl_read(box, line);
	return (res);
}
