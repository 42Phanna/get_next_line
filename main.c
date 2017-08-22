/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:09:01 by phanna            #+#    #+#             */
/*   Updated: 2017/08/22 06:37:44 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
//	int		fd2;

	ac = 0;
	line = ft_memalloc(BUFF_SIZE);
	fd = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
	get_next_line(fd, &line);
//	ft_putendl("=======");
//	get_next_line(fd2, &line);
//	ft_putendl("=======");
	get_next_line(fd, &line);
//	get_next_line(fd2, &line);
//	ft_putendl("=======");
//	get_next_line(fd, &line);
//	ft_putendl("=======");
//	get_next_line(fd2, &line);
//	ft_putendl("=======");
	return (0);
}
