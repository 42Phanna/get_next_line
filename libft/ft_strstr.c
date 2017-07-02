/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:29:52 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 00:18:49 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	if (tmp[i] == '\0' && tofind[i] != '\0')
		return (0);
	if (tmp[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0')
	{
		j = 0;
		while (tmp[i + j] == tofind[j] && tofind[j] != '\0')
			j++;
		if (tofind[j] == '\0')
			return (tmp + i);
		i++;
	}
	return (0);
}
