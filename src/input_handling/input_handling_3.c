/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:13:20 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/02 15:56:00 by ttokesi          ###   ########.fr       */
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

void	ft_error(char *str)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}
