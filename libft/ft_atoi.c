/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:15:24 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/16 03:49:39 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (ft_strchr(" \n\t\v\f\r", str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (sign * num);
}
