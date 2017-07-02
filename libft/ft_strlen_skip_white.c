/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_skip_white.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 03:30:10 by phanna            #+#    #+#             */
/*   Updated: 2017/04/25 03:30:15 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_skip_white(const char *s)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == ',' || s[i] == '\t' || s[i] == '\n')
		++i;
	if (s[i] == '\0')
		return (0);
	while (s[end] == 32 || s[end] == ',' || s[end] == '\t' || s[end] == '\n')
		--end;
	return (end - i);
}
