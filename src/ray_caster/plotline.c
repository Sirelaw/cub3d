/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:39:00 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/09 17:13:46 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_v(int *dxy, int *xyi, int *count)
{
	*count = 0;
	if (*dxy < 0)
	{	
		*xyi = -1;
		*dxy = -1 * (*dxy);
	}
}

static void	plotlinelow(int x0_y0[2], int x1_y1[2], t_vars *vars)
{
	int	dx;
	int	dy;
	int	yi;
	int	diff;
	int	count;

	dx = x1_y1[0] - x0_y0[0];
	dy = x1_y1[1] - x0_y0[1];
	yi = 1;
	diff = (2 * dy) - dx;
	init_v(&dy, &yi, &count);
	while (x0_y0[0] <= x1_y1[0])
	{
		my_mlx_pixel_put(vars, x0_y0[0], x0_y0[1], 0x00FFFFFF);
		if (diff > 0)
		{
			x0_y0[1] = x0_y0[1] + yi;
			diff = diff + (2 * (dy - dx));
		}
		else
			diff = diff + (2 * dy);
		(x0_y0[0])++;
	}
}

static void	plotlinehigh(int x0_y0[2], int x1_y1[2], t_vars *vars)
{
	int	dx;
	int	dy;
	int	xi;
	int	diff;
	int	count;

	dx = x1_y1[0] - x0_y0[0];
	dy = x1_y1[1] - x0_y0[1];
	xi = 1;
	diff = (2 * dx) - dy;
	init_v(&dx, &xi, &count);
	while (x0_y0[1] <= x1_y1[1])
	{
		my_mlx_pixel_put(vars, x0_y0[0], x0_y0[1], 0x00FFFFFF);
		if (diff > 0)
		{
			x0_y0[0] = x0_y0[0] + xi;
			diff = diff + (2 * (dx - dy));
		}
		else
			diff = diff + (2 * dx);
		(x0_y0[1])++;
	}
}

void	plotline(int point1[2], int point2[2], t_vars *vars)
{
	int	x0_y0[2];
	int	x1_y1[2];

	x0_y0[0] = (point1[0] * vars->sizer) + vars->origin[0];
	x0_y0[1] = (point1[1] * vars->sizer) + vars->origin[1];
	x1_y1[0] = (point2[0] * vars->sizer) + vars->origin[0];
	x1_y1[1] = (point2[1] * vars->sizer) + vars->origin[1];
	if (ft_absolute(x1_y1[1] - x0_y0[1]) < ft_absolute(x1_y1[0] - x0_y0[0]))
	{
		if (x0_y0[0] > x1_y1[0])
			plotlinelow(x1_y1, x0_y0, vars);
		else
			plotlinelow(x0_y0, x1_y1, vars);
		return ;
	}
	else if (x0_y0[1] > x1_y1[1])
		plotlinehigh(x1_y1, x0_y0, vars);
	else
		plotlinehigh(x0_y0, x1_y1, vars);
}
