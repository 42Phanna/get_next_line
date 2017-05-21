/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/05/21 06:16:56 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_box(char *box, char *buff, char **line)
{
	int		i;
	int		tmpi;
	char	*rest;

	i = 0;
	while (box[i] && box[i] != '\n')
		++i;
	tmpi = i;
	i = 0;
	if (box[i] == '\n')
	{
		while (i < tmpi)
		{
			*line[i] = box[i];
			++i;
		}

// OU METTRE *REST ~ BUFF? //

		while (box[i])
		{
			*rest = box [i];
			++rest;
			++i;
		}
		return (1);
	}

// STOCKER BOX DANS LINE //
	
	return (0);
}

// STRUCT SOON //

int	get_next_line(const int fd, char **line)
{
	char		*box;
	char		*buff;
	int			ret;

	while ((ret = read(fd, buff, BUFF_SIZE) > 0))
	{
		buff[ret] = '\0';
		box = ft_strjoin(box, buff);
		if (ft_check_box(box, buff, line) == 1)
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	**line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, line);
}
