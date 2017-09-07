/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/09/07 17:16:45 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_box	*fd_select(const int fd, t_box **first)
{
	t_box	*bro_tips;

	if (!(*first))
	{
		if (!((*first) = (t_box *)malloc(sizeof(t_box))) ||
				!((*first)->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		(*first)->fd = (int)fd;
		(*first)->next = NULL;
		return (*first);
	}
	bro_tips = *first;
	while (bro_tips->next && bro_tips->fd != fd)
		bro_tips = bro_tips->next;
	if (bro_tips->fd != fd)
	{
		if (!(bro_tips = (t_box *)malloc(sizeof(t_box))) ||
				!(bro_tips->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		bro_tips->fd = (int)fd;
		bro_tips->next = *first;
		*first = bro_tips;
		return (*first);
	}
	return (bro_tips);
}

char			*ft_strccpy(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		++i;
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	dst = ft_strncpy(dst, src, i);
	return (dst);
}

int				ft_found_eol(t_box *box, char **line)
{
	if (!(ft_strchr(box->buff, '\n')))
		return (0);
	*line = ft_strccpy(*line, box->buff, '\n');
	ft_putstr("LINE = ");
	ft_putendl(*line);
	box->buff = ft_strchr(box->buff, '\n');
	++box->buff;
	return (1);
}

int				gnl_read(t_box *box, char **line)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	if (ft_found_eol(box, line))
		return (1);
	tmp = NULL;
	while ((ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		ft_putstr("box->buff = ");
		ft_putendl(box->buff);
		tmp = box->buff;
		ft_putstr("tmp = ");
		ft_putendl(tmp);
		box->buff = ft_strjoin(box->buff, buffer);
		ft_putendl("bef_free");
		if (tmp)
			free(tmp);
		ft_putendl("af_free");
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

	ft_putendl("FUNCTION CALL");
	box = fd_select(fd, &first);
	if (fd < 0 || !line || !box)
		return (-1);
	ft_putendl("FD_SELECT OK");
	res = gnl_read(box, line);
//	ft_putstr("BOX->BUFF = ");
//	ft_putstr(box->buff);
	return (res);
}
