/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:09:18 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/27 23:11:33 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	putin_ray_h(t_vars *vars, t_ray* ray)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
		&& ray->my < vars->map_height
		&& vars->input[ray->my][ray->mx] == '8')
	{
		vars->par.put_in = 1;
		vars->par.point_h[0] = ray->rx;
		vars->par.point_h[1] = ray->ry;
		vars->par.dist[0] = get_dist(vars->player[0], vars->player[1],
		vars->putin[0], vars->putin[1]);
	}
}

static void	look_up_down(t_vars *vars, t_ray* ray)
{
	ray->dof = 0;
	while (ray->dof < vars->map_height)
	{
		ray->mx = (int)(ray->rx) >> TILE_BIT;
		ray->my = (int)(ray->ry) >> TILE_BIT;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
			&& ray->my < vars->map_height
			&& vars->input[ray->my][ray->mx] == '1')
		{
			ray->point_h[0] = ray->rx;
			ray->point_h[1] = ray->ry;
			ray->dist[0] = get_dist(vars->player[0], vars->player[1],
				ray->rx, ray->ry);
			ray->dof = vars->map_height;
		}
		else
		{
			// my_mlx_pixel_put(vars, (int)ray->ry, (int)ray->rx, 0x000000);
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
		// if (ray->dof != vars->map_height)
			putin_ray_h(vars, ray);
	}
}

void	init_look_up_down(t_vars *vars, t_ray* ray, float theta)
{
	if (theta > M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT) - 0.00015;
		ray->rx = (vars->player[1] - ray->ry) * ray->aTan + vars->player[0];
		ray->yo = -TILE_SIZE;
		ray->xo = -ray->yo * ray->aTan;
	}
	else if (theta < M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT) + TILE_SIZE;
		ray->rx = (vars->player[1] - ray->ry) * ray->aTan + vars->player[0];
		ray->yo = TILE_SIZE;
		ray->xo = -ray->yo * ray->aTan;
	}
	if (theta == 0 || theta == M_PI)
	{
		ray->rx = vars->player[0];
		ray->ry = vars->player[1];
		ray->dof = vars->map_height;
	}
	look_up_down(vars, ray);
}