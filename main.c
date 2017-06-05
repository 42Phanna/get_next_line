/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:09:01 by phanna            #+#    #+#             */
/*   Updated: 2017/06/05 05:47:05 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	ac = 0;
	line = ft_memalloc(BUFF_SIZE);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	return (0);
}
