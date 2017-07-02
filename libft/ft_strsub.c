/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:30:16 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 00:11:16 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*tab;

	i = 0;
	if (s)
	{
		if (!(tab = ((char*)malloc(sizeof(char) * (len + 1)))))
			return (0);
		while (s[start] && len)
		{
			tab[i] = s[start];
			++i;
			++start;
			--len;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}
