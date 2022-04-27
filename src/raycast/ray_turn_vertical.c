/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:09:18 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/27 14:43:17 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	norm_veritcal_ray_maker(t_vars *g)
{
	int mx;
	int my;
	int mp;

	while (g->ray.dof < g->map_width)
	{
		mx = (int)(g->ray.rx)>>6;
		my = (int)(g->ray.ry)>>6;
		mp = my * g->map_width + mx; // what is map x?
		// if (mp > 0 && mp < g->map_width * g->map_height && g->input[my][mx] == '8')
		if (mx > 0 && my > 0 && mx < 64 && my < 64 && g->input[my][mx] == '8')
		{
			g->ray.put_in = 1;
			g->ray.putin_rx = g->ray.rx;
			g->ray.putin_ry = g->ray.ry;
		}
		// if (mp > 0 && mp < g->map_width * g->map_height && g->input[my][mx] == '1')
		if (mx > 0 && my > 0 && mx < 64 && my < 64 && g->input[my][mx] == '1')
		{
			g->ray.dof = g->map_width; // hit wall
		}
		else
		{
			g->ray.rx += g->ray.xo;
			g->ray.ry += g->ray.yo;
			g->ray.dof += 1; // next line
		}
	}
}

void	vertical_ray_maker(t_vars *g)
{
	g->ray.dof = 0;
	float ntan = -tan(g->ray.ra);
	if (g->ray.ra > M_PI / 2 && g->ray.ra < 3 * M_PI / 2) // looking left
		{
			g->ray.rx = (((((int)g->player[0]))>>6)<<6) - 0.0001;
			g->ray.ry = (g->player[0] - g->ray.rx) * ntan + g->player[1];
			g->ray.xo = -g->ray.ofset;
			g->ray.yo = -g->ray.xo * ntan;
		}
		if (g->ray.ra < M_PI / 2 || g->ray.ra > (3 * M_PI) / 2) //looking right
		{
			g->ray.rx = ((((int)g->player[0])>>6)<<6) + g->ray.ofset;
			g->ray.ry = (g->player[0] - g->ray.rx) * ntan + g->player[1];
			g->ray.xo = g->ray.ofset;
			g->ray.yo = -g->ray.xo * ntan;
		}
		if (g->ray.ra == 0 || g->ray.ra == M_PI)
		{
			g->ray.rx = g->player[0];
			g->ray.ry = g->player[1];
			g->ray.dof = g->map_width; // looking straight up  donw
		}
	norm_veritcal_ray_maker(g);
}

static void	draw_wall_ii(t_vars *vars, int i, int *j, float line_h)
{
	int		k;
	int		l;
	int		temp;
	int		image;

	temp = line_h;
	k = 0;
	if (vars->ray.type == 0)
	{
		if (vars->ray.ry >= vars->player[1])  // ray->point[1]
			image = SO;
		else
			image = NO;
	}
	else
	{
		if (vars->ray.rx >= vars->player[0]) // ray->point[0]
			image = WE;
		else
			image = EA;
	}
	while(temp-- && *j < vars->win_h)
	{
		if (vars->ray.type == 0)
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
				(int)vars->ray.rx % vars->image[image].width,
				(vars->ray.cutoff++ * vars->image[image].height) / line_h));
		else
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
				(int)vars->ray.ry % vars->image[image].width,
				(vars->ray.cutoff++ * vars->image[image].height) / line_h));
		(*j)++;
	}
}

void	draw_line_ii(t_vars *vars, int i, float line_h)
{
	int	fill;
	int	j;
	int	k;
	int	l;

	j = 0;
	// k = 0;
	vars->ray.cutoff = 0; // old ray offset
	fill = vars->win_h - line_h;
	fill /= 2;
	if (fill < 0)
		vars->ray.cutoff = -1 * fill;
	vars->par.offset = vars->ray.cutoff;
	while (j < fill)
		my_mlx_pixel_put(vars, i, j++, vars->ceiling_color);
	int t = j;
	draw_wall_ii(vars, i, &j, line_h);
	while (j < vars->win_h)
		my_mlx_pixel_put(vars, i, j++, vars->floor_color);
	// printf("%d \n", vars->par.put_in);
	// if (vars->par.put_in == 1 &&  vars->par.one_put < 21)
	// {
	// 	// in some cases teh rays don't hit putin so this never runs....
	// 	// why is not hitting by the ray?? 
	// 	// go over exchange functions make them norm ready and step by step check the flow
	// 	// why does it skip some putin, why isnt catching it???
		
	// 	vars->par.hight = (vars->image[PUTIN64].height * vars->win_h) / vars->par.putin_dist;
	// 	vars->par.ofset_h = vars->par.hight / TILE_SIZE;
	// 	draw_putin(vars, i, t, ray);
	// 	vars->par.one_put++;
	// }
}