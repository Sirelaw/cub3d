/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:25:49 by oipadeol          #+#    #+#             */
/*   Updated: 2022/01/06 22:30:20 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	check_input_get_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "*****************************************\n", 42);
		write(1, "*  Enter the required set of arguments. *\n", 42);
		write(1, "*Input should have the following format.*\n", 42);
		write(1, "*$>./fdf map.fdf                        *\n", 42);
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

t_list	*input_rows(int argc, char **argv)
{
	t_list	*input;
	int		fd;
	char	*map_string;
	int		row_number;
	t_node	*t_row;

	row_number = 0;
	fd = check_input_get_fd(argc, argv);
	map_string = get_next_line(fd);
	t_row = str_to_row(map_string, row_number++);
	input = ft_lstnew(t_row);
	while (map_string)
	{
		free(map_string);
		map_string = get_next_line(fd);
		if (map_string)
		{
			t_row = str_to_row(map_string, row_number++);
			ft_lstadd_back(&input, ft_lstnew(t_row));
		}
	}	
	check_equal_size(input);
	return (input);
}
