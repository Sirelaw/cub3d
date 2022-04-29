/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:01:04 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/29 19:53:26 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ray->door = 0;
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
	plot_line_angle(vars->player, theta, ray.lineH / SCALE_TO_MINI, vars);
	if (vars->par.put_in == 1)
	{
		vars->par.putin_img_x = i;
		vars->par.putin_img_y = vars->win_h / 2 - ray.lineH / 2;
		if (vars->shoot == 1 && vars->orient - 0.001 < theta && vars->orient + 0.001 > theta)
		{
			vars->colore_shift++;
			// printf("orient: %f, theta: %f", vars->orient, theta);
		}

	}
	draw_line(vars, i, &ray);
}

int colore_shift(int color, int scale)
{
	int mask = 0xFF;

	int a = (color >> 24) & mask;
	int r = (color >> 16) & mask;
	int g = (color >> 8) & mask;
	int b = color & mask;

	// convert to decimal form:
	float rDecimal = r / 255; 
	// Let r: 0x66 = 102 => rDecimal: 0.4

	// darken with 50%, basically divide it by two
	rDecimal = r * scale; 
	// rDecimal: 0.2

	// Go back to original representation and put it back to r
	r = (int)(rDecimal * 255); 
	// r: 51 = 0x33

	// Put it all back in place
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
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
				{

					// colore += (colore >> 8) + 255;
					// colore += (colore << 8) - 255;
					// colore += (colore << 16) + 150;
					// colore = colore & 25;
					if (vars->colore_shift > 0)
						colore = colore_shift(colore, vars->colore_shift);
					my_mlx_pixel_put(vars, vars->par.put_point_x[i],  445 + j, colore); // 445 is to set the postiion y to place the figure on the screen
				}
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
	// int j;

	i = 0;
	while (i < 64)
	{
		// j = 0;
		// vars->par.put_point_higth[i] = -1;
		vars->par.put_point_x[i] = -1;
		// while (j < 64)
		// {
		// 	vars->par.points_x[i][j] = -1;
		// 	vars->par.points_y[i][j] = -1;
		// 	vars->par.points_colore[i][j] = -1;
		// 	j++;
		// }
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
	theta = vars->orient - M_PI / 6;
	dtheta = (M_PI / 3.0) / vars->win_w;
	vars->door_flag = 0;
	vars->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	vars->par.one_put = 0;
	fill_putin_arays(vars);
	while (i++ < vars->win_w)
	{
		vars->par.put_in = 0;
		theta += dtheta;
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	draw_putin_arays(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	draw_mini_map(vars);
}
