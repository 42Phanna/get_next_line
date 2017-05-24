/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/05/22 17:10:51 by phanna           ###   ########.fr       */
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
	ft_putstr(*box);
//	ft_putchar('\n');
	while (((*box)[i]) != '\n')
		++i;
	tmpi = i;
	ft_putstr("whileOK\n");
	if ((*box)[i] == '\n')
	{
		ft_putstr("ifOK\n");
		i = 0;
		while (i < tmpi)
		{
			ft_putstr("whileOK?\n");
			(*line)[i] = (*box)[tmpi + i + 1];
			++i;
			ft_putnbr(i);
			ft_putchar('\n');
		}
/*		while (box[i])
		{
			box[j] = box[i];
			++j;
			++i;
		}
		return (1);*/
	}
	ft_putstr("EndOfCheck\n");

	return (0);
}

// STRUCT SOON //

int	get_next_line(const int fd, char **line)
{
	static char	*box;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!box)
		box = ft_memalloc(1);
//	ft_putstr("before while\n");
	while ((ret = read(fd, buff, BUFF_SIZE + 1)) > 0)
	{
		buff[ret] = '\0';
		ft_putstr("ret = ");
		ft_putnbr(ret);
		ft_putchar('\n');
//		ft_putstr("after read\n");
//		buff[ret] = '\0';
//		ft_putstr("before join OK\n");
		box = ft_strjoin(box, buff);
//		ft_putstr("after join OK\n");
		if (ft_check_box(&box, buff, line) == 1)
			return (1);
	}
//	ft_putstr("after while\n");
	return (0);
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
//	ft_putnbr(fd);
//	ft_putchar('\n');
//	ft_putstr("GNL call\n");
	get_next_line(fd, &line);
//	ft_putstr("after GNL call\n");
	return(0);
}
