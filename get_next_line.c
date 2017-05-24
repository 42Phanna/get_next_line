/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/05/24 11:11:37 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_box(char **box, char *buff, char **line)
{
	int		i;
	int		j;
	int		tmpi;

	i = 0;
	j = 0;
	while (((*box)[i]) != '\n')
		++i;
	tmpi = i;
	if ((*box)[i] == '\n')
	{
		i = 0;
		while (i < tmpi)
		{
			(*line)[i] = (*box)[i];
			++i;
		}
	}
	while((j < ft_strlen(*box)) && (*box)[i + 1])
	{
		(*box)[j] = (*box)[i + 1];
		++j;
		++i;
	}
	ft_strclr(*box + j);
	if (*line)
		return (1);
	return (0);
}

// STRUCT SOON MAYBE //

int	get_next_line(const int fd, char **line)
{
	static char	*box;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!box)
		box = ft_memalloc(1);
	while ((ret = read(fd, buff, BUFF_SIZE + 1)) > 0)
	{
		buff[ret] = '\0';
		box = ft_strjoin(box, buff);
		if (ft_check_box(&box, buff, line) == 1)
		{
			ft_putstr(box);
			return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	line = ft_memalloc(BUFF_SIZE);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	return(0);
}
