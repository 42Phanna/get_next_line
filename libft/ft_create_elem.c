/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:04:36 by phanna            #+#    #+#             */
/*   Updated: 2017/04/28 14:20:44 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(list));
	if (!list)
		return (list);
	list->content = data;
	list->next = NULL;
	return (list);
}
