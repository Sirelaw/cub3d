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

float	fix_fisheye_get_height(t_vars *vars, float distance, float angle_diff)
{
	float	lineH;

	if (angle_diff > 2 * M_PI)
		angle_diff -= 2 * M_PI;
	else if (angle_diff < 0)
		angle_diff += 2 * M_PI;
	distance = distance * cos(angle_diff);
	if (distance < 1)
		distance = 1;
	lineH = TILE_SIZE * vars->win_h / distance;
	return (lineH);
}

void define_ray_parameters(t_vars *vars, t_ray *ray, float theta)
{
	ray->dist[0] = 1000000;
	ray->dist[1] = 1000000;
	vars->par.dist[0] = 1000000;
	vars->par.dist[1] = 1000000;
	ray->aTan = -1 / tan(theta);
	ray->nTan = -tan(theta);
}


static void	cast_ray(t_vars *vars, float theta, int i)
{
	t_ray	ray;

	define_ray_parameters(vars, &ray, theta);
	init_look_up_down(vars, &ray, theta);
	init_look_left_right(vars, &ray, theta);
	if (ray.dist[0] < ray.dist[1])
	{
		ray.distance = ray.dist[0];
		ray.point[0] = ray.point_h[0];
		ray.point[1] = ray.point_h[1];
		ray.type = 0;
	}
	else
	{
		ray.distance = ray.dist[1];
		ray.point[0] = ray.point_v[0];
		ray.point[1] = ray.point_v[1];
		ray.type = 1;
	}
	if (vars->par.dist[0] < vars->par.dist[1])
	{
		vars->par.putin_dist = vars->par.dist[0];
		vars->par.type = 1;
	}
	else
	{
		vars->par.type = 0;
		vars->par.putin_dist = vars->par.dist[1];
	}

	ray.lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	plot_line_angle(vars->player, theta, 5, vars);
	if (vars->par.put_in == 1)
	{
		vars->par.putin_img_x = i;
		vars->par.putin_img_y = vars->win_h / 2 - ray.lineH / 2;
	}
	draw_line(vars, i, &ray);
}

void draw_putin_arays(t_vars *vars)
{
	int i;
	int j;
	int colore;
	double	adj;

	i = 0;
	adj = vars->par.hight - 40; // 40 is to set the starting size - is bigger + is smaller.
	while (i < adj)
	{
		j = 0;
		while (j < adj)
		{
			if (vars->par.put_point_x[(int)((i * TILE_SIZE) / adj)] != -1)
			{
				colore = get_pixel(&vars->image[PUTINS], (i * TILE_SIZE) / adj, (j * TILE_SIZE) / adj);
				if (colore != 0xFFFFFF)
					my_mlx_pixel_put(vars, vars->par.put_point_x[i],  445 + j, colore); // 445 is to set the postiion y to place the figure on the screen
			}
			// colore = vars->par.points_colore[i][j];
			// if (colore != -1)
			// 	my_mlx_pixel_put(vars, vars->par.points_x[i][j] + 64, vars->par.points_y[i][j] , colore);
			j++;
		}
		i++;
	}
}

void fill_putin_arays(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		vars->par.put_point_higth[i] = -1;
		vars->par.put_point_x[i] = -1;
		while (j < 64)
		{
			vars->par.points_x[i][j] = -1;
			vars->par.points_y[i][j] = -1;
			vars->par.points_colore[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	cast_rays(t_vars *vars)
{
	int		i;
	float	dtheta;
	float	theta;
	int		point[2];

	i = 0;
	theta = vars->orient - M_PI / 6;  // this angles and staff was handeled differently
	dtheta = (M_PI / 3.0) / vars->win_w;
	vars->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	// printf("---------------------cycle---------------------\n");
	vars->par.one_put = 0;
	fill_putin_arays(vars);
	while (i++ < vars->win_w)
	{
		vars->par.put_in = 0;
		theta += dtheta; // it was incremented end of cycle
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	draw_putin_arays(vars);
	// printf("x:%d y:%d\n", vars->putin[0], vars->putin[1]);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	
	// if (vars->par.put_in == 1)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PUTIN].load,
	// 		vars->par.putin_img_x , vars->par.putin_img_y);
	draw_field(vars);
}
