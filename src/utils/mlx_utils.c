#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if ((x >= WIN_WIDTH) || (y >= WIN_HEIGHT) || (x < 0) || (y < 0))
		return ;
	dst = vars->addr + (y * vars->line_lenght + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *image, int x, int y)
{
	char	*color;

	color = image->addr + (y * image->line_lenght + x * (image->bits_per_pixel / 8));
	return (*(unsigned int *) color);
}

int	render_next_rays(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	// if (vars->this_ends != -1)
	// 	end_the_game(vars, vars->this_ends);
	cast_rays(vars);
	return (0);
}

void	rotate_player(int keycode, t_vars *vars)
{
	if (keycode == RIGHT_KEY)
		vars->orient += 0.2;
	else if (keycode ==  LEFT_KEY)
		vars->orient -= 0.2;
	if (vars->orient > 2 * M_PI)
		vars->orient -= 2 * M_PI;
	else if (vars->orient < 0)
		vars->orient += 2 * M_PI;
	vars->player_d[0] = cosf(vars->orient);
	vars->player_d[1] = sinf(vars->orient);
}

static void	check_valid_position(float temp[2], t_vars *vars)
{
	int dist;

	dist = get_dist(vars->player[0], vars->player[1], vars->putin[0], vars->putin[1]);
	if (dist < 1 * TILE_SIZE)
		return ;
	if ((vars->input)[(int)temp[1] >> TILE_BIT][(int)temp[0] >> TILE_BIT]
		!= '1')
	{
		vars->player_f[0] = temp[0];
		vars->player_f[1] = temp[1];
		vars->player[0] = temp[0];
		vars->player[1] = temp[1];
		vars->simul_loop++;
		vars->simul_loop = vars->simul_loop & 15;
	}
}

void	move_image(int keycode, t_vars *vars)
{
	float temp[2];

	temp[0] = vars->player_f[0];
	temp[1] = vars->player_f[1];
	if (keycode == A_KEY)
	{
		temp[0] += STEP * vars->player_d[1];
		temp[1] -= STEP * vars->player_d[0];
	}
	else if (keycode == D_KEY)
	{
		temp[0] -= STEP * vars->player_d[1];
		temp[1] += STEP * vars->player_d[0];
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		temp[0] -= STEP * vars->player_d[0];
		temp[1] -= STEP * vars->player_d[1];
	}
	else if (keycode == W_KEY || keycode == UP_KEY)
	{
		temp[0] += STEP * vars->player_d[0];
		temp[1] += STEP * vars->player_d[1];
	}
	check_valid_position(temp, vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		clean_destroy(vars);
	if (keycode == 123 || keycode == 124)
		rotate_player(keycode, vars);
	else if (keycode == A_KEY || keycode == D_KEY || keycode == S_KEY
			|| keycode == W_KEY || keycode == UP_KEY || keycode == DOWN_KEY)
		move_image(keycode, vars);
	else if (keycode == 257 || keycode == 258)
	{
		if (vars->shoot == 0)
		{
			
			vars->shoot = 1;
			vars->simul_loop += 2;
		}
	}
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	if (vars->mouse < x / STEP)
		rotate_player(RIGHT_KEY, vars);
	else if (vars->mouse > x / STEP)
		rotate_player(LEFT_KEY, vars);
	vars->mouse = x / STEP;
	return (0);
}

void	free_all(t_vars *vars)
{
	char	**input;
	int		i;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
	free(vars->image[NO].path);
	free(vars->image[SO].path);
	free(vars->image[EA].path);
	free(vars->image[WE].path);
}

int	clean_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_all(vars);
	exit(EXIT_SUCCESS);
}