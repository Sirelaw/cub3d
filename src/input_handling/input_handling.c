/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:25:49 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/05 15:26:39 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_input_get_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "*****************************************\n", 42);
		write(1, "*  Enter the required set of arguments. *\n", 42);
		write(1, "*Input should have the following format.*\n", 42);
		write(1, "*$>./fdf map.cub                        *\n", 42);
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

char	**input_rows(int argc, char **argv)
{
	char	**input;
	int		fd;
	char	*map_row;

	input = NULL;
	fd = check_input_get_fd(argc, argv);
	map_row = get_next_line(fd);
	input = add_to_arr(&input, map_row);
	while (map_row)
	{
		map_row = get_next_line(fd);
		if (map_row)
			input = add_to_arr(&input, map_row);
	}	
	check_valid(input);
	return (input);
}
