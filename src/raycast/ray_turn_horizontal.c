/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:09:18 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/27 14:29:33 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	norm_horisontal_ray_maker(t_vars *g)
{
	int mx;
	int my;
	int mp;

	// printf("hello 1\n");
	while (g->ray.dof < g->map_height)
	{
		mx = (int)(g->ray.rx) / g->ray.ofset;
		my = (int)(g->ray.ry) / g->ray.ofset;
		mp = my * g->map_width + mx;
	// printf("hello 2\n");
		// if (mp > 0 && mp < g->map_width * g->map_height && g->input[my][mx] == '1')
		if (mx > 0 && my > 0 && mx < 64 && my < 64 && g->input[my][mx] == '1')
		{
			g->ray.dof = g->map_height; // hit wall
		}
		else
		{
	// printf("hello 3\n");
			g->ray.rx += g->ray.xo;
			g->ray.ry += g->ray.yo;
			g->ray.dof += 1; // next line
		}
	}
}

void	horisontal_ray_maker(t_vars *g)
{
	g->ray.dof = 0;
	float aTan = -1 / tan(g->ray.ra);
	if (g->ray.ra > M_PI) // looking up
	{
		g->ray.ry = (((int)(g->player[1])>>6)<<6) - 0.0001;
		g->ray.rx = (g->player[1] - g->ray.ry) * aTan + g->player[0];
		g->ray.yo = -g->ray.ofset;
		g->ray.xo = -g->ray.yo * aTan;
	}
	if (g->ray.ra < M_PI) //looking down
	{
		g->ray.ry = (((int)(g->player[1])>>6)<<6) + g->ray.ofset;
		g->ray.rx = (g->player[1] - g->ray.ry) * aTan + g->player[0];
		g->ray.yo = g->ray.ofset;
		g->ray.xo = -g->ray.yo * aTan;
	}
	if (g->ray.ra == 0 || g->ray.ra == M_PI)
	{
		g->ray.rx = g->player[0];
		g->ray.ry = g->player[1];
		g->ray.dof = g->map_height; // looking straight left or right
	}
	norm_horisontal_ray_maker(g);
}