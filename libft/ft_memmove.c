/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:51:06 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 09:46:36 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmpdst;
	const char	*tmpsrc;

	if (!len)
		return (dst);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		tmpdst = (char*)dst;
		tmpsrc = (const char *)src;
		while (--len > 0)
			tmpdst[len] = tmpsrc[len];
		tmpdst[len] = tmpsrc[len];
	}
	return (dst);
}
