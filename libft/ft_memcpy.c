/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:50:26 by phanna            #+#    #+#             */
/*   Updated: 2017/04/20 17:06:26 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
