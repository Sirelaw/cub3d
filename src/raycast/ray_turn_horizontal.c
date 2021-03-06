/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:09:18 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 16:04:17 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	putin_ray_h(t_vars *vars, t_ray *ray)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
		&& ray->my < vars->map_height
		&& vars->input[ray->my][ray->mx] == '8')
	{
		vars->par.dist[0] = get_dist(vars->player[0], vars->player[1],
				vars->putin[0], vars->putin[1]);
		if (ray->dist[0] > vars->par.dist[0])
			vars->par.put_in = 1;
	}
}

static void	look_up_down(t_vars *vars, t_ray *ray)
{
	while (ray->dof < vars->map_height)
	{
		ray->mx = (int)(ray->rx) >> TILE_BIT;
		ray->my = (int)(ray->ry) >> TILE_BIT;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
			&& ray->my < vars->map_height && (vars->input[ray->my][ray->mx]
			== '1' || vars->input[ray->my][ray->mx] == 'D'))
		{
			ray->door[0] = (vars->input[ray->my][ray->mx] == 'D');
			ray->point_h[0] = ray->rx;
			ray->point_h[1] = ray->ry;
			ray->dist[0] = get_dist(vars->player[0], vars->player[1],
					ray->rx, ray->ry);
			ray->dof = vars->map_height;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
		if (ray->dof < vars->map_height)
			putin_ray_h(vars, ray);
	}
}

void	init_look_up_down(t_vars *vars, t_ray *ray, float theta)
{
	if (theta > M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT) - 0.00015;
		ray->rx = (vars->player[1] - ray->ry) * ray->atan + vars->player[0];
		ray->yo = -TILE_SIZE;
		ray->xo = -ray->yo * ray->atan;
	}
	else if (theta < M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT)
			+ TILE_SIZE;
		ray->rx = (vars->player[1] - ray->ry) * ray->atan + vars->player[0];
		ray->yo = TILE_SIZE;
		ray->xo = -ray->yo * ray->atan;
	}
	if (theta == 0 || theta == M_PI)
	{
		ray->rx = vars->player[0];
		ray->ry = vars->player[1];
		ray->dof = vars->map_height;
	}
	ray->dof = 0;
	look_up_down(vars, ray);
}
