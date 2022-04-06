/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:51:48 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/06 17:41:46 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	// exit(1);
}

void	check_first_and_last_line(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str != '1' && *str != ' ')
			ft_error();
		str++;
	}
}

void	check_surround(char *str, char *up, char *down, size_t i)
{
	char	surround[8];

	if (i >= ft_strlen(up) - 1 || i >= ft_strlen(down) - 1)
		ft_error();
	surround[0] = up[i - 1];
	surround[1] = up[i];
	surround[2] = up[i + 1];
	surround[3] = str[i - 1];
	surround[4] = str[i + 1];
	surround[5] = down[i - 1];
	surround[6] = down[i];
	surround[7] = down[i + 1];
	i = 0;
	while (i < 8)
	{
		if (surround[i] == ' ')
			ft_error();
		i++;
	}
}

void	check_other_line(char *str, char *up, char *down, t_vars *vars)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1' || str[ft_strlen(str) - 1] != '1')
		ft_error();
	while (str[i])
	{
		if (str[i] == '0' || ft_strchr("NEWS", str[i]))
		{
			check_surround(str, up, down, i);
			if (ft_strchr("NEWS", str[i]))
			{
				if (vars->start_orientation)
					ft_error();
				vars->start_orientation = str[i];
				vars->player[0] = i;
			}
		}
		else if (str[i] != '1' && str[i] != ' ')
			ft_error();
		i++;
	}
}

int	check_valid(char **input, t_vars *vars)
{
	int		i;
	int		arr_len;

	i = 0;
	arr_len = 0;
	while (input && input[arr_len])
		arr_len++;
	while (input[i])
	{
		if ((i == 0) || (i == arr_len - 1))
			check_first_and_last_line(input[i]);
		else
		{
			if (!vars->start_orientation)
				vars->player[1] = i;
			check_other_line(input[i], input[i - 1], input[i + 1], vars);
		}
		i++;
	}
	if (!vars->start_orientation)
	{
		write(STDERR_FILENO, "Map must include one player position.\n", 38);
		ft_error();
	}
	return (0);
}
