/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:17 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/07 01:21:44 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define PI 3.1415926

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
	if (*temp2 == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * g->sizer, i * g->sizer);
	if (*temp2 == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * g->sizer, i * g->sizer);
	mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, g->fi_x, g->fi_y);
	// plotLine(g->fi_x, g->fi_y, g->fi_x + g->pdx * 5, g->fi_y + g->pdy * 5, g);

	// mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, g->bh_x, g->bh_y);
	// mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, g->b2_x, g->b2_y);
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

	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, 20 * 65, 15 * 65);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel, &g->line_length, &g->endian);
	if (key == 123) //left
	{
		g->pa -= 0.1;
		if (g->pa < 0)
		{
			g->pa += 2 * PI;
		} 
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
		// my_mlx_pixel_put(g, g->fi_x + 500, g->fi_y + 500,  0x00CCFF66);
		int ofset = 000;
		plotLine(g->fi_x + ofset, g->fi_y + ofset, g->fi_x + g->pdx * 5 + ofset, g->fi_y + g->pdy * 5 + ofset, g);
	}

	if (key == 124) //right
	{
		g->pa += 0.1;
		if (g->pa >  2 * PI)
		{
			g->pa -= 2 * PI;
		} 
		g->pdx = cos(g->pa) * 5;
		g->pdy = sin(g->pa) * 5;
		int ofset = 00;
		plotLine(g->fi_x + ofset, g->fi_y + ofset, g->fi_x + g->pdx * 5 + ofset, g->fi_y + g->pdy * 5 + ofset, g);

	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 000, 000);
}