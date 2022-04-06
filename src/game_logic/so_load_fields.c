/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_load_fields.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:52:25 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/06 21:21:12 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	side_two(t_vars *g, char *temp2, int i, int j)
{
	if ((*temp2 == 'N' || *temp2 == 'S' || *temp2 == 'E' || *temp2 == 'W') && g->check == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, j * g->sizer, i * g->sizer);
		g->map[i][j] = 0;
		g->fi_x = j * g->sizer;
		g->fi_y = i * g->sizer;
		g->check = 1;
	}
	else if (*temp2 == 'P' && g->check == 1)
	{
		g->bh_x = j * g->sizer;
		g->bh_y = i * g->sizer;
		mlx_put_image_to_window(g->mlx, g->win, g->im[5].l, g->bh_x, g->bh_y);
		g->check = 2;
	}
	else if (*temp2 == 'P' && g->check == 2)
	{
		g->b2_x = j * g->sizer;
		g->b2_y = i * g->sizer;
		mlx_put_image_to_window(g->mlx, g->win, g->im[5].l, g->bh_x, g->bh_y);
		g->check = 3;
	}
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
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * g->sizer, i * g->sizer);
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->bh_x = j * g->sizer;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->bh_y = i * g->sizer;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->b2_x = j * g->sizer;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->b2_y = i * g->sizer;
	}
	side_two(g, temp2, i, j);
}

void	load_fields(t_vars *g)
{
	int		i;
	int		j;

	g->map = malloc(g->he_y * sizeof(char *));
	if (g->map == NULL)
		return ;
	g->map = g->input;
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
