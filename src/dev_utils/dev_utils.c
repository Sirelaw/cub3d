#include "../includes/cub3d.h"

#define PRINT_HERE (printf("Here\n"))

void	print_str_arr(char **input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		printf("%s\n", input[i]);
		i++;
	}
}

// int mouse_turn(int x, int y, t_vars *game)
// {

// }