/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:07:46 by phanna            #+#    #+#             */
/*   Updated: 2017/05/04 14:30:29 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == 45)
		neg = 1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
