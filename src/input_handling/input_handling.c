/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:25:49 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/14 17:00:50 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_orient(double	*orient, char start_orientation)
{
	if (start_orientation == 'E')
		*orient = 0;
	else if (start_orientation == 'S')
		*orient = M_PI_2;
	else if (start_orientation == 'W')
		*orient = M_PI;
	else if (start_orientation == 'N')
		*orient = 3 * M_PI_2;
}

static int	check_input_get_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "*****************************************\n", 42);
		write(1, "*  Enter the required set of arguments. *\n", 42);
		write(1, "*Input should have the following format.*\n", 42);
		write(1, "*$>./cub3d map.cub                      *\n", 42);
		write(1, "*****************************************\n", 42);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	return (fd);
}

static char	**init_arr(char ***arr, char *s)
{
	*arr = malloc(sizeof(char *) * 2);
	if (*arr == NULL)
		return (NULL);
	(*arr)[0] = s;
	(*arr)[1] = NULL;
	return (*arr);
}

static char	**add_to_arr(char ***arr, char *s)
{
	int		i;
	char	**temp;

	if (*arr == NULL)
		return (init_arr(arr, s));
	i = 0;
	while ((*arr)[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while ((*arr)[i++])
		temp[i - 1] = (*arr)[i - 1];
	temp[i - 1] = s;
	temp[i] = NULL;
	free(*arr);
	*arr = temp;
	return (*arr);
}

void	input_rows_init_player(int argc, char **argv, t_vars *vars)
{
	int		fd;
	char	*map_row;

	fd = check_input_get_fd(argc, argv);
	map_row = get_line(fd);
	vars->input = add_to_arr(&vars->input, map_row);
	while (map_row)
	{
		map_row = get_line(fd);
		if (map_row)
			vars->input = add_to_arr(&vars->input, map_row);
	}
	if (vars->input)
		check_valid(vars->input, vars);
	init_orient(&vars->orient, vars->start_orientation);
	vars->player_f[0] = vars->player[0];
	vars->player_f[1] = vars->player[1];
	vars->player_d[0] = cos(vars->orient);
	vars->player_d[1] = sin(vars->orient);
	standardize_input(vars->input, &(vars->map_width));	
}
