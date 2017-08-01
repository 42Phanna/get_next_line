/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/08/01 09:18:48 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_box	*fd_select(const int fd, t_box **box)
{
	t_box	*bro_tips;

	if (!(*box))
	{
		ft_putstr("Box de ce fd n'existe pas: ");
		ft_putnbr(fd);
		ft_putendl("");
		if (!((*box) = (t_box *)malloc(sizeof(t_box))) &&
			!((*box)->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		ft_putstr("malloc_OK");
		(*box)->fd = (int)fd;
		(*box)->next = NULL;
		return (*box);
	}
	bro_tips = *box;
	while (bro_tips->next && bro_tips->fd != fd)
		bro_tips = bro_tips->next;
	if (bro_tips->fd != fd)
	{
		if (!(bro_tips = (t_box *)malloc(sizeof(t_box))) &&
			!(bro_tips->buff = (char *)malloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		bro_tips->fd = (int)fd;
		bro_tips->next = *box;
		*box = bro_tips;
		return (*box);
	}
	return (bro_tips);
}

int		gnl_check(char *buff, char **line)
{
	int	i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			*line = ft_memcpy(*line, buff, i);

			return (0);
		}
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				f;
	int				ret;
	t_box			*first;
	static t_box	*box = NULL;

	box = fd_select(fd, &first);
	ft_putendl("");
	ft_putstr("box->fd = ");
	ft_putnbr(box->fd);
	ft_putendl("");
	ft_putendl("fd_select_OK");
	ft_putendl(box->buff);
	while ((ret = read(box->fd, box->buff, 4096 + 1)))
	{
//		ft_putendl(box->buff);
		ft_putnbr(ret);
		box->buff[ret] = '\0';
		f = gnl_check(box->buff, line);
	}
	return (0);
}
