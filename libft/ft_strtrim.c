/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 00:55:37 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 10:15:06 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	size_t	lim;
	char	*tab;

	i = 0;
	j = 0;
	if (s)
	{
		lim = ft_strlen_skip_white(s) + 1;
		if (!(tab = malloc(sizeof(char) * (ft_strlen_skip_white(s) + 2))))
			return (0);
		while (s[i] == 32 || s[i] == ',' || s[i] == '\t' || s[i] == '\n')
			++i;
		while (lim--)
		{
			tab[j] = s[i + j];
			++j;
		}
		tab[j] = '\0';
		return (tab);
	}
	return (0);
}
