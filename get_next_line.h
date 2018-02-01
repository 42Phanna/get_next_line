/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:56:51 by phanna            #+#    #+#             */
/*   Updated: 2017/10/20 02:17:27 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 127
# define FD_MAX 10240
# define ERROR -1
# define SUCCESS 1

# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"
# include <fcntl.h>

int				get_next_line(const int fd, char **line);

#endif
