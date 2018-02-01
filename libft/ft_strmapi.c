/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:31:30 by phanna            #+#    #+#             */
/*   Updated: 2017/04/24 22:56:13 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (s)
	{
		if (!(tab = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (tab);
		while (s[i])
		{
			tab[i] = f(i, s[i]);
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}
