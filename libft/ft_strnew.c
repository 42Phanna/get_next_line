/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:45:12 by phanna            #+#    #+#             */
/*   Updated: 2017/04/20 15:19:24 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
