#include "../includes/cub3d.h"

void	init_vars(t_vars *vars)
{
	vars->input	= NULL;
	vars->win_w = 1200;
	vars->win_h = 700;
	vars->start_orientation = 0;
	vars->player[0] = 0;
	vars->player[1] = 0;
	vars->player_d[0] = 0;
	vars->player_d[1] = 0;
	vars->player_f[0] = 0;
	vars->player_f[1] = 0;
	vars->origin[0] = 0;
	vars->origin[1] = 0;
	vars->simul_loop = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_vars	vars2;

	init_vars(&vars);
	input_rows_init_player(argc, argv, &vars);
	vars.mlx = mlx_init();
	vars2.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_w,
			vars.win_h, "42+2 cube3D");
	img_handler(&vars);
	cast_rays(&vars);
	draw_field(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_mouse_hook (vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, clean_destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}