/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:17 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/27 14:40:36 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// #define M_PI 3.1415926
#define o_rad 0.01745 * 60 / 1280 // one degree step in radian

void define_ray_parameters(t_vars *g)
{
	g->ray.ofset = TILE_SIZE;
	g->ray.put_in = 0;
	// g->ray.putin_img_x = -1;
	g->ray.ra = g->orient - o_rad * g->win_w / 2;
	// printf("%d\n", g->win_w);
}

float dist_cal(float ax, float ay,float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}


void cyclic_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void distance_calc(t_vars *g)
{
	g->ray.dist_hor = dist_cal(g->player[0], g->player[1], g->ray.rx_horiz, g->ray.ry_horiz);
	g->ray.dist = dist_cal(g->player[0], g->player[1], g->ray.rx, g->ray.ry);

	// if (g->ray.put_in == 1)
	// 	g->ray.putin_dist = dist_cal(g->player[0], g->player[1], g->ray.putin_rx, g->ray.putin_ry);
	

	// colore = create_rgb(1, 2, 240);
	g->ray.type = 1;
	if (g->ray.dist_hor < g->ray.dist)
	{
		g->ray.rx = g->ray.rx_horiz;
		g->ray.ry = g->ray.ry_horiz;
		g->ray.dist = g->ray.dist_hor;
		g->ray.type = 0;
		// we hit a horizontal wall
	}
}

void ray_cycle(t_vars *g)
{
	int		r;

	r = 0;
	// texture_fill(g);
	// printf("hello\n 1");
	// printf("w: %d   h: %d\n", g->map_width , g->map_height);
	while (r < 1280)
	{
		g->ray.put_in = 0;
		g->ray.dist = 1000000;
		g->ray.dist_hor = 1000000;
	// printf("hello 2 -----%d\n", r);
		horisontal_ray_maker(g);
	// printf("hello 3\n");
		g->ray.rx_horiz = g->ray.rx; // save temp result of horizontal ray maker, usable data will be always in simple rx
		g->ray.ry_horiz = g->ray.ry;
		vertical_ray_maker(g);
		distance_calc(g);
		
		// plotLine(g->player[0], g->player[1], g->ray.rx, g->ray.ry, g);

		// -------------- draw 3d screen -------------
		// fish eye
		float ca = g->orient - g->ray.ra;
		cyclic_angle(&ca);
		g->ray.dist = g->ray.dist * cos(ca);
	
		float lineight = ( 80 * 960) / g->ray.dist;
		// 16 sets the virtual distance from the wall
		if (lineight > 960)
			lineight = 960;
		float lineof = 480 - lineight / 2; // line offset
		int i;
		i = 0;

		// if (g->ray.put_in == 1)
		// {
		// 	g->ray.putin_img_x = (int)(r * 3);
		// 	g->ray.putin_img_y = (int)lineof;
		// }
		
		// 	g->plot.xo = r;
		// 	g->plot.yo = lineof;
		// 	g->plot.x1 = r;
		// 	g->plot.y1 = lineight + lineof;

			// texture(g, g->ray.rx);
			// plotline_color(r, lineof, r, lineof + lineight, g, colore);
		//    480 0 shift image in x axis r * N is the widness beetween rays fill up space
		g->ray.ra += o_rad;
		cyclic_angle(&g->ray.ra);
		draw_line_ii(g, r, lineight);
	// printf("hello 4\n");
		r++;
	}

}

void ray_maker(t_vars *g)
{
	g->img = mlx_new_image(g->mlx, g->win_w, g->win_h);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel,
			&g->line_lenght, &g->endian);
	g->par.one_put = 0;
	// wale version line
	define_ray_parameters(g);
	cyclic_angle(&g->ray.ra);

// printf("---------------------cycle---------------------\n");
	ray_cycle(g);

	// wale version line
	// draw_putin_arays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	draw_field(g);
}
