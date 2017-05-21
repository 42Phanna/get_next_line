/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:56:51 by phanna            #+#    #+#             */
/*   Updated: 2017/05/21 03:46:01 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct		s_box
{
	int				fd;
	static char		*buff;
	struct s_box	*next;
}					t_box;
int	get_next_line(const int fd, char **line);
#endif
