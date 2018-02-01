/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:15:07 by phanna            #+#    #+#             */
/*   Updated: 2017/05/04 15:16:28 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int t;

	i = 0;
	t = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && t == 0)
		{
			str[i] = str[i] - 32;
			t = 0;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') && t == 1)
			str[i] = str[i] + 32;
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < '0' || str[i] > '9'))
			t = 0;
		else
			t = 1;
		i++;
	}
	return (str);
}
