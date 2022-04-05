/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:13:19 by oipadeol          #+#    #+#             */
/*   Updated: 2022/01/04 16:06:25 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	conv_to_hex(const char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (((str[i] > 47) && (str[i] < 58)) || ((str[i] > 64) && (str[i] < 71))
		|| ((str[i] > 96) && (str[i] < 103)))
	{
		if ((str[i] > 47) && (str[i] < 58))
			num = (num * 16) + (str[i] - 48);
		else if ((str[i] > 64) && (str[i] < 71))
			num = (num * 16) + (str[i] - 55);
		else if ((str[i] > 96) && (str[i] < 103))
			num = (num * 16) + (str[i] - 86);
		i++;
	}
	return (num);
}

long	ft_strtol(const char *str, char **end_ptr, int base)
{
	int		i;
	long	num;
	char	**delimiter;

	i = 0;
	num = 0;
	delimiter = end_ptr;
	if ((str == NULL) || (*str == '\0'))
		return (0);
	while (ft_strchr(" \n\t\v\f\r", str[i]))
		i++;
	while ((str[i] == '0') || (str[i] == 'x') || (str[i] == 'X'))
		i++;
	if (base == 16)
		num = conv_to_hex(&(str[i]));
	return (num);
}
