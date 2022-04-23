#include "../../includes/cub3d.h"

void plot_line_angle(int start[2], float theta, float dist, t_vars *vars)
{
	int	point[2];
	int	new_point[2];

	point[0] = start[0] / SCALE_TO_MINI;
	point[1] = start[1] / SCALE_TO_MINI;
	new_point[0] = point[0] + (dist * cosf(theta));
	new_point[1] = point[1] + (dist * sinf(theta));
	plotline(point, new_point, vars, WHITE);
}

int	fix_fisheye_get_height(t_vars *vars, float distance, float angle_diff)
{
	int	lineH;

	if (angle_diff > 2 * M_PI)
		angle_diff -= 2 * M_PI;
	else if (angle_diff < 0)
		angle_diff += 2 * M_PI;
	distance = distance * cos(angle_diff);
	if (distance < 1)
		distance = 1;
	lineH = TILE_SIZE * vars->win_h / distance;
	if (lineH > vars->win_h)
		lineH = vars->win_h;
	return (lineH);
}

void	draw_wall(t_vars *vars, int i, int *j, float lineH, int color)
{
	double	scale;
	int		k;
	int		l;
	int		temp;

	temp = lineH;
	k = 0;
	l = 0;
	while(temp--)
	{
		// my_mlx_pixel_put(vars, i, *j, color);
		my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[NIGERIA_64],
				((i & 63) * TILE_SIZE) / lineH,
				(l++ * TILE_SIZE) / lineH));
		(*j)++;
	}
}

void	draw_line(t_vars *vars, int i, float lineH, int color)
{
	int	fill;
	int	j;
	int	k;
	int	l;
	double	scale;

	j = -1;
	fill = vars->win_h - lineH;
	fill /= 2;
	scale = lineH / TILE_SIZE;
	while (j++ < fill)
		my_mlx_pixel_put(vars, i, j, 0x17e8d6);
	draw_wall(vars, i, &j, lineH, color);
	// while (lineH--)
	// 	my_mlx_pixel_put(vars, i, j++, color);
	j--;
	while (j++ < vars->win_h)
		my_mlx_pixel_put(vars, i, j, GREEN);
}

void	draw_wall_ray(t_vars *vars, int i, int *j, float lineH, t_ray *ray)
{
	double	scale;
	int		k;
	int		l;
	int		temp;

	temp = lineH;
	k = 0;
	l = 0;
	// lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	// plot_line_angle(vars->player, theta, 8, vars);
	while(temp--)
	{
		if (ray->type == 0)
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[BRICKWALL_GRAY],
				ray->point[0] & 63,
				(l++ * TILE_SIZE) / lineH));
		else
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[BRICKWALL_DARK],
				ray->point[1] & 63,
				(l++ * TILE_SIZE) / lineH));
		(*j)++;
	}
}


void	draw_line_ray(t_vars *vars, int i, float lineH, t_ray *ray)
{
	int	fill;
	int	j;
	int	k;
	int	l;
	double	scale;

	j = -1;
	fill = vars->win_h - lineH;
	fill /= 2;
	scale = lineH / TILE_SIZE;
	while (j++ < fill)
		my_mlx_pixel_put(vars, i, j, 0x17e8d6);
	draw_wall_ray(vars, i, &j, lineH, ray);
	// while (lineH--)
	// 	my_mlx_pixel_put(vars, i, j++, color);
	j--;
	while (j++ < vars->win_h)
		my_mlx_pixel_put(vars, i, j, GREEN);
}

static void	cast_ray(t_vars *vars, float theta, int i)
{
	t_ray	ray;
	float	lineH;
	int		color;

	ray.dist[0] = 1000000;
	ray.dist[1] = 1000000;
	ray.aTan = -1 / tan(theta);
	ray.nTan = -tan(theta);
	init_look_up_down(vars, &ray, theta);
	init_look_left_right(vars, &ray, theta);
	if (ray.dist[0] < ray.dist[1])
	{
		ray.distance = ray.dist[0];
		ray.point[0] = ray.point_h[0];
		ray.point[1] = ray.point_h[1];
		color = 0xd617e8;
		ray.type = 0;
	}
	else
	{
		ray.distance = ray.dist[1];
		ray.point[0] = ray.point_v[0];
		ray.point[1] = ray.point_v[1];
		color = 0xe8d617;
		ray.type = 1;
	}
	lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	plot_line_angle(vars->player, theta, 8, vars);
	// draw_line(vars, i, lineH, color);
	if (vars->par.put_in == 1)
	{
		vars->par.putin_img_x = i;
		vars->par.putin_img_y = vars->win_h / 2 - lineH / 2;
	}
	draw_line_ray(vars, i, lineH, &ray);
}

void	cast_rays(t_vars *vars)
{
	int		i;
	float	dtheta;
	float	theta;
	int		point[2];

	i = 0;
	theta = vars->orient - M_PI / 6;
	dtheta = (M_PI / 3.0) / vars->win_w;
	vars->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	// vars->par.put_in = 0;
	while (i++ < vars->win_w)
	{
		theta += dtheta;
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	
	if (vars->par.put_in == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PUTIN].load,
			vars->par.putin_img_x , vars->par.putin_img_y);
	
	draw_field(vars);
}

void	draw_field(t_vars *vars)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		j = 0;
		while(input[i][j])
		{
			if (input[i][j] == '1' && i * MINI_SIZE < vars->player[1]
				/ SCALE_TO_MINI + 50
				&& i * MINI_SIZE > vars->player[1] / SCALE_TO_MINI - 50
				&& j * MINI_SIZE < vars->player[0] / SCALE_TO_MINI + 50
				&& j * MINI_SIZE > vars->player[0] / SCALE_TO_MINI - 50)
				mlx_put_image_to_window(vars->mlx, vars->win,
				vars->image[WHITE_8].load,
				j * MINI_SIZE, i * MINI_SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->player[0] / SCALE_TO_MINI, vars->player[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->putin[0] / SCALE_TO_MINI, vars->putin[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].load,
		vars->win_w - 232 + (vars->simul_loop % 4) * 10 , vars->win_h - 232 + (vars->simul_loop % 4) * 10);
	// shooting gun
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].load,
	// 	vars->win_w - 232 + (vars->simul_loop % 2) * 10 , vars->win_h - 232 + (vars->simul_loop % 2) * 10);
	// draw_gun(vars);
}
