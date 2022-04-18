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

void	draw_line(t_vars *vars, int i, float lineH, int color)
{
	int	fill;
	int	j;
	int	k;
	int	l;

	j = -1;
	fill = vars->win_h - lineH;
	fill /= 2;
	while (j++ < fill)
		my_mlx_pixel_put(vars, i, j, 0x17e8d6);
	while (lineH--)
		my_mlx_pixel_put(vars, i, j++, color);
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
	}
	else
	{
		ray.distance = ray.dist[1];
		ray.point[0] = ray.point_v[0];
		ray.point[1] = ray.point_v[1];
		color = 0xe8d617;
	}
	lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	plot_line_angle(vars->player, theta, 8, vars);
	draw_line(vars, i, lineH, color);
}

void	cast_rays(t_vars *vars)
{
	int		i;
	float	dtheta;
	float	theta;
	int		point[2];

	i = 0;
	theta = vars->orient - M_PI / 6;
	dtheta = (M_PI / 3.0) / 1200;
	vars->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	while (i++ < 1200)
	{
		theta += dtheta;
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
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
				vars->image[WHITE_8].l,
				j * MINI_SIZE, i * MINI_SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].l,
	vars->player[0] / SCALE_TO_MINI, vars->player[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].l,
		vars->win_w - 232 + vars->simul_loop, vars->win_h - 232 + vars->simul_loop);
	// draw_gun(vars);
}
