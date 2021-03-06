/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:51:48 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/03 12:36:49 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_first_and_last_line(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str != '1' && *str != ' ')
			ft_error("Non 1 or space in 1st or last line.");
		str++;
	}
}

static void	check_surround(char *str, char *up, char *down, size_t i)
{
	char	surround[8];

	if (i >= ft_strlen(up) - 1 || i >= ft_strlen(down) - 1)
		ft_error("0 found after a shorter neighbouring line.");
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
			ft_error("0 bordered by one or more spaces.");
		i++;
	}
}

static void	check_other_line_norm(char *str, int i, t_vars *vars)
{
	if (ft_strchr("NEWS", str[i]))
	{
		if (vars->start_orientation)
			ft_error("More than one NEWS in map.");
		vars->start_orientation = str[i];
		vars->player[0] = i * TILE_SIZE;
	}
	if (str[i] == '0' && vars->putin[0] == 0)
	{
		vars->putin[0] = i * TILE_SIZE + 17;
		vars->putin[1] = vars->player[1] + 17;
	}
}

static void	check_other_line(char *str, char *up, char *down, t_vars *vars)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1' || str[ft_strlen(str) - 1] != '1')
		ft_error("Line doesn't start or end with 1.");
	while (str[i])
	{
		if (str[i] == '0' || ft_strchr("NEWS", str[i]))
		{
			check_surround(str, up, down, i);
			check_other_line_norm(str, i, vars);
		}
		else if (str[i] != '1' && str[i] != ' ' && str[i] != 'D')
			ft_error("Non 1 or space or 0 in map.");
		i++;
	}
}

int	check_valid(char **input, t_vars *vars)
{
	int		i;

	i = 0;
	vars->map_height = 0;
	while (input && input[vars->map_height])
		vars->map_height++;
	while (input[i])
	{
		if ((i == 0) || (i == vars->map_height - 1))
			check_first_and_last_line(input[i]);
		else
		{
			if (!vars->start_orientation)
				vars->player[1] = i * TILE_SIZE;
			check_other_line(input[i], input[i - 1], input[i + 1], vars);
		}
		i++;
	}
	if (!vars->start_orientation)
		ft_error("Map must include one player position.");
	return (0);
}
