/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/08/14 18:48:30 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_box	*fd_select(const int fd, t_box **box)
{
	t_box	*bro_tips;

	if (!(*box))
	{
//		ft_putstr("Box de ce fd n'existe pas: ");
//		ft_putnbr(fd);
//		ft_putendl("");
		if (!((*box) = (t_box *)malloc(sizeof(t_box))) ||
			!((*box)->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
//		ft_putendl("malloc_OK");
		(*box)->fd = (int)fd;
		(*box)->next = NULL;
		return (*box);
	}
	bro_tips = *box;
	while (bro_tips->next && bro_tips->fd != fd)
		bro_tips = bro_tips->next;
	if (bro_tips->fd != fd)
	{
		if (!(bro_tips = (t_box *)malloc(sizeof(t_box))) ||
			!(bro_tips->buff = (char *)malloc(BUFF_SIZE + 1)))
			exit(EXIT_FAILURE);
		bro_tips->fd = (int)fd;
		bro_tips->next = *box;
		*box = bro_tips;
		return (*box);
	}
	return (bro_tips);
}

int		gnl_read(t_box *box, char *line)
{
	int		i;
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	i = 0;
	ft_putendl("in_gnl_read");
	while ((ret = read(box->fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		ft_putendl("buffer = ");
		ft_putstr(buffer);
		box->buff = ft_strjoin(box->buff, buffer);
		if (ft_strchr(box->buff, '\n'))
		{
			ft_putendl("\'\\n\' found");
			while (*box->buff != '\n')
			{
				*(line + i) = *box->buff;
//				ft_putendl("@@@@@@@@@");
//				ft_putchar(*line);
//				ft_putendl("@@@@@@@@@");
				++i;
				box->buff++;
			}
			ft_putstr("line: ");
			ft_putendl(line);
//			++i;
//			ft_putnbr(i);
//			ft_bzero(box->buff, (size_t)i);
			ft_putstr(box->buff);
			return (1);
		}
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	t_box			*first;
	static t_box	*box = NULL;

	first = NULL;
	box = fd_select(fd, &first);
	ft_putendl("fd_select_OK");
	if (gnl_read(box, *line) == 1)
		return (1);
	return (0);
}
