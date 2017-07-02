/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:28:55 by phanna            #+#    #+#             */
/*   Updated: 2017/04/22 18:13:14 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		f;
	int		t;
	char	tmp;
	char	*tmp2;

	i = 0;
	f = 0;
	t = 0;
	tmp = (char)c;
	tmp2 = (char *)s;
	if (c == '\0')
		return (tmp2 + ft_strlen((char *)s));
	while (tmp2[i] != '\0')
	{
		if (tmp2[i] == tmp)
		{
			f = i;
			t = 1;
		}
		++i;
	}
	if (t == 1)
		return (tmp2 + f);
	return (0);
}
