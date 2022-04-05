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

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.input = input_rows(argc, argv);
	print_str_arr(vars.input);
	return (0);
}