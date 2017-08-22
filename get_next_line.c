/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/08/22 06:37:42 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_box	*fd_select(const int fd, t_box **first)
{
	t_box	*bro_tips;

	if (!(*first))
	{
		if (!((*first) = (t_box *)malloc(sizeof(t_box))) || !((*first)->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
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
		if (!(bro_tips = (t_box *)malloc(sizeof(t_box))) || !(bro_tips->buff = (char *)malloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		bro_tips->fd = (int)fd;
		bro_tips->next = *first;
		*first = bro_tips;
		return (*first);
	}
	return (bro_tips);
}

char			*gnl_read(t_box *box, char *line)
{
	int		ret;
	char	*str;
	char	buffer[BUFF_SIZE + 1];

	while ((ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		box->buff = ft_strjoin(box->buff, buffer);
		ft_putendl(box->buff);
		if ((str = ft_strchr(box->buff, '\n')))
		{
			ft_putstr("str =");
			ft_putstr(str);
			return (str);
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	t_box			*first;
	static t_box	*box = NULL;

	if(box == NULL)
		first = NULL;
	box = fd_select(fd, &first);
	if (((*line) = gnl_read(box, *line)))
	{
		ft_putstr("line: ");
		ft_putendl(*line);
		ft_putstr("box->buff: ");
		ft_putstr(box->buff);
		return (1);
	}
	return (0);
}
