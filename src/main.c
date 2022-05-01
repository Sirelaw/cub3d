#include "../includes/cub3d.h"

static void	init_vars(t_vars *vars)
{
	vars->input	= NULL;
	vars->win_w = 1280;
	vars->win_h = 920;
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
	vars->par.putin_step = 32;
	vars->par.putin_time = 0;
	vars->putin[0] = 0;
	vars->putin[1] = 0;
	vars->par.put_in = 0;
	vars->par.type = 0;
	vars->shoot = 0;
	vars->colore_shift = 0;
	vars->mouse = 0;
	// printf("%f\n", ((float)vars->win_w / vars->win_h) - 0.1);
}

static int	frame_func(t_vars *vars)
{
	if (vars->colore_shift <= KILL_SHOT || vars->colore_shift != -1)
	{
		putin_run(vars);
	}
	else
		vars->shoot = 0;
	return (0);
}

void	*make_sound(void *some)
{
	t_vars	*vars;

	vars = (t_vars *)some;
	while (1)
	{
		if (vars->shoot)
			system("afplay ./sounds/gunshot.mp3");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	pthread_t sounding;

	ft_bzero(&vars, sizeof(vars));
	init_vars(&vars);
	input_rows_init_player(argc, argv, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_w,
			vars.win_h, "42+2 cube3D");
	img_handler(&vars);
	cast_rays(&vars);
	pthread_create(&sounding, NULL, make_sound, &vars);
	pthread_detach(sounding);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 0, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, clean_destroy, &vars);
	mlx_loop_hook(vars.mlx, frame_func, &vars);
	mlx_loop(vars.mlx);
	//handle keypress in hook
	return (0);
}