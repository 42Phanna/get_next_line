/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 00:42:05 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 00:54:22 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = -1;
	j = -1;
	if (s1 && s2)
	{
		if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (tab);
		while (s1[++i])
			tab[i] = s1[i];
		while (s2[++j])
			tab[i + j] = s2[j];
		tab[i + j] = '\0';
		return (tab);
	}
	return (0);
}
