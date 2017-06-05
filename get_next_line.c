/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/06/05 05:47:39 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_check_box(char *box, char **line)
{
	int		i;
	int		j;
	char	*rest = NULL;

	i = 0;
	j = -1;
	rest = ft_memalloc(4096);
	while (box[i] && box[i] != '\n')
		++i;
	if (box[i] == '\n')
		*line = ft_strsub(box, 0, i);
	while (box[++i])
		rest[++j] = box[i];
	rest[j] = '\0';
	ft_strcpy(box, rest);
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
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		box = ft_strjoin(box, buff);
		if (ft_check_box(box, line) == 1)
		{
			ft_putstr(box);
			return (1);
		}
	}
	return (0);
}
