/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 04:55:37 by phanna            #+#    #+#             */
/*   Updated: 2017/04/26 12:52:21 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_strsplit(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

static void	ft_fill_mal(char const *str, char *mal, int lenf)
{
	int	i;

	i = 0;
	while (i < lenf)
	{
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
}

static int	ft_calcul_p(char const *str, char c)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			p++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (p);
}

char		**ft_strsplit(char const *str, char c)
{
	int		p;
	int		i;
	int		j;
	int		lenf;
	char	**mal;

	if (!str)
		return (0);
	p = ft_calcul_p(str, c);
	if (!(mal = (char **)malloc(sizeof(mal) * (p + 1))))
		return (mal);
	i = 0;
	j = -1;
	while (++j < p)
	{
		while (str[i] && str[i] == c)
			i++;
		lenf = ft_strlen_strsplit(str + i, c);
		if (!(mal[j] = (char *)malloc(sizeof(*mal) * (lenf + 1))))
			return (mal);
		ft_fill_mal(str + i, mal[j], lenf);
		i = i + lenf;
	}
	mal[j] = 0;
	return (mal);
}
