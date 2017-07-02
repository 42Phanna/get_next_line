/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 09:34:57 by phanna            #+#    #+#             */
/*   Updated: 2017/04/30 15:32:35 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*tmp_new;

	tmp_new = f(lst);
	new = tmp_new;
	if (lst && f)
	{
		while (lst->next)
		{
			lst = lst->next;
			tmp_new->next = f(lst);
			tmp_new = tmp_new->next;
		}
		return (new);
	}
	return (0);
}
