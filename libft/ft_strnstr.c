/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:52:52 by phanna            #+#    #+#             */
/*   Updated: 2017/04/21 14:10:00 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	if (tmp[i] == '\0' && tofind[i] != '\0')
		return (0);
	if (tmp[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0' && len > i)
	{
		j = 0;
		while (tmp[i + j] == tofind[j] && tofind[j] != '\0' && len > j + i)
			j++;
		if (tofind[j] == '\0')
			return (tmp + i);
		i++;
	}
	return (0);
}
