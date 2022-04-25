/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putin_movments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:48:49 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/25 20:15:27 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	st_p(t_vars *g, int x, int y)
{
	int dist;

	if (g->input[y / TILE_SIZE][x / TILE_SIZE] == '1'/*  && y / TILE_SIZE > 1 && x / TILE_SIZE > 1 && g->input[y / TILE_SIZE - 1][x / TILE_SIZE - 1] == '1' */)
		return (0);
	dist = get_dist(g->player[0], g->player[1], g->putin[0], g->putin[1]);
	if (dist < TILE_SIZE)
		return (0);
	return (1);
}

static void	flipper_two(int *step, t_vars *g)
{
	if (step[0] == g->par.putin_step && step[1] == 0)
	{
		step[0] = 0;
		step[1] = -g->par.putin_step;
	}
	else if (step[0] == -g->par.putin_step && step[1] == 0)
	{
		step[0] = 0;
		step[1] = g->par.putin_step;
	}
	else if (step[0] == 0 && step[1] == g->par.putin_step)
	{
		step[0] = g->par.putin_step;
		step[1] = 0;
	}
	else if (step[0] == 0 && step[1] == -g->par.putin_step)
	{
		step[0] = -g->par.putin_step;
		step[1] = 0;
	}
	else
	{
		step[0] = g->par.putin_step;
		step[1] = 0;
	}
}

static void	flipper(t_vars *g, int *step, int x, int y)
{
	int	sign;
	int exitcount;

	step[0] = g->par.putin_step;
	step[1] = g->par.putin_step;
	step[2] = '\0';
	sign = rand() % 2;
	if (sign == 0)
		step[1] = 0;
	else
		step[0] = 0;
	sign = rand() % 2;
	if (g->player[0] < x && sign == 0)
	{
		step[0] = -g->par.putin_step;
		step[1] = 0;
	}
	if (g->player[1] < y && sign == 1)
	{
		step[0] = 0;
		step[1] = -g->par.putin_step;
	}
	exitcount = 0;
	// while (!st_p(g, x + step[0], y + step[1]) && exitcount < 20)
	// {
	// 	flipper_two(step, g);
	// 	exitcount++;
	// }
	if (!st_p(g, x + step[0], y + step[1]))
	{
		step[0] = 0;
		step[1] = 0;
	}
// 	if (exitcount == 20)
// 	{
// 		step[0] = 0;
// 		step[1] = 0;
// 	}
}

static void	enemymaker(t_vars *g, int *step)
{
	flipper(g, step, g->putin[0], g->putin[1]);
	(g->input)[g->putin[1] / TILE_SIZE][g->putin[0] / TILE_SIZE] = '0';
		// printf("x: %d   y: %d\n", g->putin[0] / TILE_SIZE, g->putin[1] / TILE_SIZE);
		// g->map2[g->putin[1] * g->wi_x / 8 + g->putin[0] / 8] = 0;
	g->putin[0] = g->putin[0] + step[0];
	g->putin[1] = g->putin[1] + step[1];
	(g->input)[g->putin[1] / TILE_SIZE][g->putin[0] / TILE_SIZE] = '8';
}

int	putin_run(t_vars *g)
{
	int	f;
	int	step[3];

	(g->par.putin_time)++;
	if (g->par.putin_time == 50 && g->putin[0] != -1 && g->putin[1] != -1)
		enemymaker(g, step);
	if (g->par.putin_time == 100 && g->putin[0] != -1 && g->putin[1] != -1)
	{
		g->par.putin_time = 0;
	}
	// plotLine(g->fi_x, g->fi_y, g->fi_x + g->pdx * 5, g->fi_y + g->pdy * 5, g);
	return (0);
}
