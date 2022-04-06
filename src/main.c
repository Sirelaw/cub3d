#include "../includes/cub3d.h"

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

void	init_vars(t_vars *vars)
{
	vars->input	= NULL;
	vars->start_orientation = 0;
	vars->player[0] = 0;
	vars->player[1] = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	input_rows(argc, argv, &vars);
	game_starter(&vars, 23, 48);
	print_str_arr(vars.input);
	return (0);
}