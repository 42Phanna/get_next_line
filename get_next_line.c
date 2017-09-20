/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/09/20 17:09:49 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_box	*fds(const int fd, t_box **first)
{
	t_box	*bro_tips;

	if (!(*first))
	{		
		if (!((*first) = (t_box *)malloc(sizeof(t_box))) || 
			!((*first)->buff = (char *)malloc(BUFF_SIZE + 1)))
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
			!(bro_tips->buff = (char *)malloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
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
		dst = ft_strncpy(dst, src, i);
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}

int				ft_found_eol(t_box *box, char **line)
{
	if (!box->buff || !(ft_strchr(box->buff, '\n')))
		return (0);
	*line = ft_strcdup(*line, box->buff, '\n');
	box->buff = ft_strchr(box->buff, '\n');
	if ((box->buff)[0])
		++box->buff;
	return (1);
}

int				gnl_read(t_box *box, char **line)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	if (!(ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		if (!box->buff[0])
			return (0);
//		*line = ft_strcdup(*line, box->buff, '\0');
		box->buff[0] = '\0';
		return (1);
	}
	buffer[ret] = '\0';
	box->buff = ft_strjoin(box->buff, buffer);
	if (ft_found_eol(box, line))
		return (1);
	while ((ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		box->buff = ft_strjoin(box->buff, buffer);
		if (ft_found_eol(box, line))
			return (1);
	}
	*line = ft_strcdup(*line, box->buff, '\0');
	box->buff[0] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_box	*first = NULL;
	t_box			*box;
	int				res;
	char			test[0];
	
	if (fd < 0 || !line || read(fd, test, 0) < 0 || !(box = fds(fd, &first)))
		return (-1);
	if (ft_found_eol(box, line))
		return (1);
	res = gnl_read(box, line);
	return (res);
}
