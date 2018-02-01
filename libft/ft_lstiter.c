/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 09:06:21 by phanna            #+#    #+#             */
/*   Updated: 2017/04/28 09:17:18 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst)
	{
		f(tmp_lst);
		tmp_lst = tmp_lst->next;
	}
}
