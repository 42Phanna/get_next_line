/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:23 by phanna            #+#    #+#             */
/*   Updated: 2017/04/20 17:42:33 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	if (!n)
		return (0);
	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && i < n - 1)
		i++;
	if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
