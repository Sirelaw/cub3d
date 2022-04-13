/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:17 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/13 20:56:32 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// #define M_PI 3.1415926
#define o_rad 0.001745 // one degree step in radian

void	my_mlx_pixel_put(t_vars *game, int x, int y, int color)
{
	char	*dst;

	if (x > 1280 || x < 0 || y < 0 || y > 960)
		return ;
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

void define_ray_parameters(t_vars *g, t_rays *para)
{
	para->ra = g->pa;
}

float dist_cal(float ax, float ay,float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void ray_maker(t_vars *g)
{
	int r;
	int mx;
	int my;
	int mp;
	int dof; // debth of field
	int px;
	int py;
	float rx;
	float ry;
	float rx_horiz;
	float ry_horiz;
	float ra;
	float xo;
	float yo;
	int mapX = g->wi_x; // size of map
	int mapY = g->he_y; // size of map
	int mapS = mapX * mapY; // size of map
	int ofset = 8; //size of M_pixel

	ra = g->pa - o_rad * 300;
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;

	// if (ra == 0)
	// 	ra = 0.1;
	// if (ra > 6.2831)
	// 	ra = 6.2;
	// if (ra > 1.5 && ra < 1.6)
	// 	ra = 1.5;
	// 6,28319
	// 6.283185 
	// printf("player x: %d \n", g->fi_x);
	px = g->fi_x;
	py = g->fi_y;
	r = 0;
	while (r < 600)
	{
		// check horizontal lines -----------------------------
		dof = 0;
		float aTan = -1 / tan(ra);
		if (ra > M_PI) // looking up
		{
			ry = (((int)py>>3)<<3) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -ofset;
			xo = -yo * aTan;
		}
		if (ra < M_PI) //looking down
		{
			ry = (((int)py>>3)<<3) + ofset;
			rx = (py - ry) * aTan + px;
			yo = ofset;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == M_PI)
		{
			rx = px;
			ry = py;
			dof = g->he_y; // looking straight left or right
		}
		while (dof < g->he_y)
		{
			mx = (int)(rx) / ofset;
			my = (int)(ry) / ofset;
			mp = my * mapX + mx; // what is map x?
			if (mp > 0 && mp < mapX * mapY && (g->map2[mp] == 1 || g->map2[mp] == 8))
			{
				dof = g->he_y; // hit wall
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1; // next line
			}
		}

		//---------------------------------------------
		rx_horiz = rx;
		ry_horiz = ry;


		// --------------vertical -------------------------
		// P2 == PI /2
		// P3 == 3 * PI / 2

		dof = 0;
		float nTan = -tan(ra);
		if (ra > M_PI / 2 && ra < 3 * M_PI / 2) // looking left
		{
			rx = (((int)px>>3)<<3) - 0.0001;
			ry = (px - rx) * nTan + py;
			xo = -ofset;
			yo = -xo * nTan;
		}
		if (ra < M_PI / 2 || ra > (3 * M_PI) / 2) //looking right
		{
			rx = (((int)px>>3)<<3) + ofset;
			ry = (px - rx) * nTan + py;
			xo = ofset;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == M_PI)
		{
			rx = px;
			ry = py;
			dof = g->wi_x; // looking straight up  donw
		}
		while (dof < g->wi_x)
		{
			mx = (int)(rx)>>3;
			my = (int)(ry)>>3;
			mp = my * mapX + mx; // what is map x?
			if (mp > 0 && mp < mapX * mapY && (g->map2[mp] == 1 || g->map2[mp] == 8))
			{
				dof = g->wi_x; // hit wall
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1; // next line
			}
		}

		float dist_hor;
		float dist;
		
		dist_hor = dist_cal(g->fi_x, g->fi_y, rx_horiz, ry_horiz);
		dist = dist_cal(g->fi_x, g->fi_y, rx, ry);
		int colore;

		colore = create_rgb(1, 2, 240);
		//------------------
		if (dist_hor < dist)
		{
			rx = rx_horiz;
			ry = ry_horiz;
			dist = dist_hor;
			colore = create_rgb(1, 58, 240);
			// we hit a horizontal wall
		}
		// int ofset = 0;
		// printf("bef left\n");
		// printf("x: %f   y: %f    agle: %f\n", rx, ry, xo);
		plotLine(g->fi_x, g->fi_y, rx, ry, g);


		// -------------- draw 3d screen -------------
		// fish eye
		float ca = g->pa - ra;
		if (ca < 0)
			ca += 2 * M_PI;
		if (ca > 2 * M_PI)
			ca -= 2 * M_PI;
		dist = dist * cos(ca);
	
		float lineight = 16 * 960 / dist;
		// 16 sets the virtual distance from the wall
		if (lineight > 960)
			lineight = 960;
		float lineof = 480 - lineight / 2; // line offset
		int i;
		i = 0;
		while (i < 3)
		{
			plotline_color(r * 3 + 0 + i, lineof, r * 3 + 0 + i, lineof + lineight, g, colore);
			i++;
		}
		//    480 0 shift image in x axis r * N is the widness beetween rays fill up space

		// printf("aft left\n");sssdd
		ra += o_rad;
		if (ra < 0)
			ra += 2 * M_PI;
		if (ra > 2 * M_PI)
			ra -= 2 * M_PI;

		r++;
	}
}

void look_around(int key, t_vars *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, 1280, 960);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel, &g->line_length, &g->endian);
	game_screen_maker(g);
	if (key == 123) //turn left
	{
		g->pa -= 0.1;
		if (g->pa < 0)
			g->pa += 2 * M_PI;
		ray_maker(g);
	}
	if (key == 124) //turn right
	{
		g->pa += 0.1;
		if (g->pa > 2 * M_PI)
			g->pa -= 2 * M_PI;
		ray_maker(g);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 000, 000);
}