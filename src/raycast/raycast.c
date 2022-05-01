/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:01:04 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/02 00:14:28 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	distance_calculations(t_vars *vars, t_ray *ray)
{
	if (ray->dist[0] < ray->dist[1])
	{
		ray->distance = ray->dist[0];
		ray->point[0] = ray->point_h[0];
		ray->point[1] = ray->point_h[1];
		ray->type = 0;
	}
	else
	{
		ray->distance = ray->dist[1];
		ray->point[0] = ray->point_v[0];
		ray->point[1] = ray->point_v[1];
		ray->type = 1;
	}
	if (vars->par.dist[0] < vars->par.dist[1])
	{
		vars->par.putin_dist = vars->par.dist[0];
	}
	else
	{
		vars->par.putin_dist = vars->par.dist[1];
	}
}

static void	cast_ray(t_vars *vars, float theta, int i)
{
	t_ray	ray;

	define_ray_parameters(vars, &ray, theta);
	init_look_up_down(vars, &ray, theta);
	init_look_left_right(vars, &ray, theta);
	distance_calculations(vars, &ray);
	ray.lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	plot_line_angle(vars->player, theta, ray.distance / SCALE_TO_MINI, vars);
	if (vars->par.put_in == 1)
	{
		if (vars->par.one_side_flag == -1)
			vars->par.all_in = 1;
		if (vars->shoot == 1 && vars->orient - 0.001 < theta && vars->orient + 0.001 > theta)
			vars->colore_shift++;
	}
	draw_line(vars, i, &ray);
}

static void fill_putin_arays(t_vars *vars)
{
	int i;

	i = 0;
	while (i < 1280)
	{
		vars->par.put_point_x[i] = -1;
		i++;
	}
}

void	cast_rays(t_vars *vars)
{
	int		i;
	float	dtheta;
	float	theta;

	i = 0;
	theta = vars->orient - M_PI / 6;
	dtheta = (M_PI / 3.0) / WIN_WIDTH;
	vars->open_door = vars->open_door && vars->simul_loop;
	if (vars->last_door[0] || vars->last_door[1])
		vars->input[vars->last_door[1]][vars->last_door[0]] = 'D';
	vars->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	vars->par.one_put = 0;
	vars->par.all_in = 0;
	vars->par.one_side_flag = -1;
	fill_putin_arays(vars);
	while (i++ < WIN_WIDTH)
	{
		vars->par.put_in = 0;
		theta += dtheta;
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	if (vars->par.all_in == 1)
		draw_putin_arays(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	draw_field(vars);
}
