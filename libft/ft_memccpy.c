/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:10:22 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 10:56:47 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!n)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (n && i < n && s[i++] != c)
		;
	ft_memcpy(dst, src, i);
	if (dst && d[i - 1] == c)
		return (dst + i);
	return (NULL);
}
