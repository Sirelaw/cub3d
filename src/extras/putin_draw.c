/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putin_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:57:52 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 15:59:43 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_putin(t_vars *vars, int i, t_ray *ray)
{
	if (vars->par.put_in == 1)
	{
		vars->par.hight = (vars->image[PUTINS].height * WIN_HEIGHT)
			/ vars->par.putin_dist;
		vars->par.ofset_h = vars->par.hight / TILE_SIZE;
		if (vars->par.putin_dist < ray->distance)
		{
			vars->par.put_point_x[vars->par.one_put] = i;
		}
		vars->par.one_put++;
	}
}

static int	colore_shift(int color, int scale)
{
	int		a;
	int		r;
	int		g;
	int		b;
	float	rdecimal;

	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	rdecimal = r / 255;
	rdecimal = r * scale;
	r = (int)(rdecimal * 255);
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

static void	draw_putin_arays_norm(t_vars *vars, int colore, int i, int j)
{
	if (vars->colore_shift > 0)
		colore = colore_shift(colore, vars->colore_shift);
	my_mlx_pixel_put(vars, vars->par.put_point_x[i],
		POSITION_PUTIN_Y + j, colore);
}

void	draw_putin_arays(t_vars *vars)
{
	int		i;
	int		j;
	int		colore;
	double	adj;

	i = 0;
	adj = vars->par.hight - RELATIVE_SIZE_PUTIN;
	while (i < adj)
	{
		j = 0;
		while (j < adj)
		{
			if (vars->par.put_point_x[(int)((i * TILE_SIZE) / adj)] != -1)
			{
				colore = get_pixel(&vars->image[PUTINS],
						(i * TILE_SIZE) / adj, (j * TILE_SIZE) / adj);
				if (colore != 0xFFFFFF)
					draw_putin_arays_norm(vars, colore, i, j);
			}
			j++;
		}
		i++;
	}
}
