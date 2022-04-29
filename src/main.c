#include "../includes/cub3d.h"

void	init_vars(t_vars *vars)
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
	// new
	vars->par.putin_step = 32;
	vars->par.putin_time = 0;
	vars->putin[0] = 0;
	vars->putin[1] = 0;
	vars->par.put_in = 0;
	vars->par.type = 0;
	vars->this_ends = -1;
	vars->shoot = 0;
	vars->colore_shift = 0;
	vars->putin_dead = 0;
	vars->mouse = 0;
}

int frame_func(t_vars *vars)
{
	// vars->par.put_in = 0;
	// render_next_rays(vars); // put inside putin run so not renders everyting all the time just every second blink
	if (vars->colore_shift <= KILL_SHOT)
	{
		putin_run(vars);
	}
	// else
	// 	printf("hello here\n");
	// if (vars->par.put_in == 1)
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PUTIN].load,
		// 	vars->par.putin_img_x , vars->par.putin_img_y);
	return (0);
}

void *make_sound(void *some)
{
	t_vars	*vars;

	vars = (t_vars *)some;
	while (1)
	{
		// usleep(50);
		if (vars->shoot)
			system("afplay ./sounds/gunshot.mp3");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	pthread_t sounding;

	init_vars(&vars);
	input_rows_init_player(argc, argv, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_w,
			vars.win_h, "42+2 cube3D");
	img_handler(&vars);

	cast_rays(&vars);
	pthread_create(&sounding, NULL, make_sound, &vars);

// mlx_put_image_to_window(vars.mlx, vars.win, vars.image[LOST].load, 50, 50);
	
	draw_field(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	// mlx_mouse_hook (vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 0, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, clean_destroy, &vars);
	mlx_loop_hook(vars.mlx, frame_func, &vars);
	mlx_loop(vars.mlx);
	//handle keypress in hook

	return (0);
}