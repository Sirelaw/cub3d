/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:09:18 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 16:04:42 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by))));
}

static void	putin_ray_v(t_vars *vars, t_ray *ray)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
		&& ray->my < vars->map_height
		&& (vars->input)[ray->my][ray->mx] == '8')
	{
		vars->par.dist[1] = get_dist(vars->player[0], vars->player[1],
				vars->putin[0], vars->putin[1]);
		if (ray->dist[1] > vars->par.dist[1])
			vars->par.put_in = 1;
	}
}

static void	look_left_right(t_vars *vars, t_ray *ray)
{
	while (ray->dof < vars->map_width)
	{
		ray->mx = (int)(ray->rx) >> TILE_BIT;
		ray->my = (int)(ray->ry) >> TILE_BIT;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
			&& ray->my < vars->map_height
			&& (vars->input[ray->my][ray->mx] == '1'
			|| vars->input[ray->my][ray->mx] == 'D'))
		{
			ray->door[1] = (vars->input[ray->my][ray->mx] == 'D');
			ray->point_v[0] = ray->rx;
			ray->point_v[1] = ray->ry;
			ray->dist[1] = get_dist(vars->player[0], vars->player[1], ray->rx,
					ray->ry);
			ray->dof = vars->map_width;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
		if (ray->dof < vars->map_width)
			putin_ray_v(vars, ray);
	}
}

void	init_look_left_right(t_vars *vars, t_ray *ray, float theta)
{
	if (theta > M_PI_2 && theta < 3 * M_PI_2)
	{
		ray->rx = (((int)(vars->player[0]) >> TILE_BIT) << TILE_BIT) - 0.00015;
		ray->ry = (vars->player[0] - ray->rx) * ray->ntan + vars->player[1];
		ray->xo = -TILE_SIZE;
		ray->yo = -ray->xo * ray->ntan;
	}
	if (theta < M_PI_2 || theta > 3 * M_PI_2)
	{
		ray->rx = (((int)(vars->player[0]) >> TILE_BIT) << TILE_BIT)
			+ TILE_SIZE;
		ray->ry = (vars->player[0] - ray->rx) * ray->ntan + vars->player[1];
		ray->xo = TILE_SIZE;
		ray->yo = -ray->xo * ray->ntan;
	}
	if (theta == M_PI_2 || theta == 3 * M_PI_2)
	{
		ray->rx = vars->player[0];
		ray->ry = vars->player[1];
		ray->dof = vars->map_width;
	}
	ray->dof = 0;
	look_left_right(vars, ray);
}
