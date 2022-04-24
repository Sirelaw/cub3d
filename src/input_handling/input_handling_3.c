/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:13:20 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/24 23:13:21 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	standardize_input(char **str_ptr, int *max_len)
{
	int		max;
	int		i;
	char	*temp;

	max = 0;
	i = 0;
	while (str_ptr[i++])
		if (max < ft_strlen(str_ptr[i - 1]))
			max = ft_strlen(str_ptr[i - 1]);
	i = 0;
	while (str_ptr[i])
	{
		if (ft_strlen(str_ptr[i]) < max)
		{
			temp = malloc(max + 1);
			if (!temp)
				ft_error("Malloc error in standardize input.");
			ft_strlcpy(temp, str_ptr[i], max);
			free(str_ptr[i]);
			str_ptr[i] = temp;
		}
		i++;
	}
	*max_len = max;
}