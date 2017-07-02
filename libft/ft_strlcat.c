/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 06:19:08 by phanna            #+#    #+#             */
/*   Updated: 2017/04/30 15:00:14 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;

	i = -1;
	j = -1;
	lend = 0;
	if (!(size))
		return (ft_strlen(src));
	while (dst[++i] && lend < size)
		lend++;
	while (src[++j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
	}
	if (lend < size)
		dst[i] = '\0';
	return (lend + ft_strlen(src));
}
