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

int	clean_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// free_all(vars);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	// if ((mousecode == 4) || (mousecode == 5))
	// {
	// 	zoom_image(mousecode, x, y, vars);
	// 	render_next_frame(vars);
	// }
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		clean_destroy(vars);
	// if (((keycode >= 0) && (keycode <= 2)) || ((keycode >= 12)
	// 		&& (keycode <= 14)))
	// 	rotate_image(keycode, vars);
	// else if ((keycode >= 123) && (keycode <= 126))
	// 	move_image(keycode, vars);
	// render_next_frame(vars);
	return (0);
}

void	init_vars(t_vars *vars)
{
	vars->input	= NULL;
	vars->start_orientation = 0;
	vars->player_x = 0;
	vars->player_y = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	input_rows(argc, argv, &vars);
	print_str_arr(vars.input);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1024,
	// 		550, "CUB3D by 42+2");
	// vars.img = mlx_new_image(vars.mlx, 1024, 550);
	// vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
	// 		&vars.line_lenght, &vars.endian);
	// // draw_wire_frame(vars, vars.input);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	// mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	// mlx_mouse_hook (vars.win, mouse_hook, &vars);
	// mlx_hook(vars.win, 17, 0, clean_destroy, &vars);
	// mlx_loop(vars.mlx);
	return (0);
}