/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:17 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/06 23:11:33 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define PI 3.14159265359

void	my_mlx_pixel_put(t_vars *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	side_one(t_vars *g, char *temp2, int i, int j)
{
	if (*temp2 == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->im[WALL].l, j * g->sizer, i * g->sizer);
	if (*temp2 == ' ')
		mlx_put_image_to_window(g->mlx, g->win, g->im[NONE].l, j * g->sizer, i * g->sizer);
	if (*temp2 == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * g->sizer, i * g->sizer);
	mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, j * g->sizer, i * g->sizer);
}

void	render_smallmap(t_vars *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g->input[i] && i < g->he_y)
	{
		j = 0;
		while (g->input[i][j] && j < g->wi_x)
		{
			side_one(g, &g->input[i][j] , i, j);
			j++;
		}
		i++;
	}
}

void look_around(int key, t_vars *g)
{
	float pa = 0; // player angle
	float pdx = 0; // delta x
	float pdy = 0;
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, 20 * 65, 15 * 65);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel, &g->line_length, &g->endian);
	if (key == 123) //left
	{
		pa -= 0.1;
		if (pa < 0)
		{
			pa += 2 * PI;
		} 
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
		my_mlx_pixel_put(g, g->fi_x + 500, g->fi_y + 500,  0x00CCFF66);
		// plotLine(g->fi_x, g->fi_y, g->fi_x + pdx, g->fi_y + pdy, g);
	}

	if (key == 124) //right
	{
		pa -= 0.1;
		if (pa >  2 * PI)
		{
			pa -= 2 * PI;
		} 
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;

	}
		mlx_put_image_to_window(g->mlx, g->win, g->img, 000, 000);
}