/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:32:32 by phanna            #+#    #+#             */
/*   Updated: 2017/04/19 13:23:47 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mal;

	mal = (void *)malloc(sizeof(*mal) * size);
	if (!mal)
		return (0);
	ft_bzero(mal, size);
	return (mal);
}
