/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putin_movments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:48:49 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 13:39:53 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	st_p(t_vars *g, int x, int y)
{
	int dist;

	if ((g->input[y / TILE_SIZE][x / TILE_SIZE] == '1'
		|| g->input[(y - 10) / TILE_SIZE][(x - 10) / TILE_SIZE] == '1'
		|| g->input[(y + 10) / TILE_SIZE][(x + 10) / TILE_SIZE] == '1')
		|| g->input[y / TILE_SIZE][x / TILE_SIZE] == 'D')
		return (0);
	dist = get_dist(g->player[0], g->player[1], g->putin[0], g->putin[1]);
	if (dist < 1 * TILE_SIZE)
	{
		g->colore_shift = -1;
		// end_the_game(g, 0);
		return (0);
	}
	return (1);
}

static void	flipper(t_vars *g, int *step, int x, int y)
{
	int	sign;
	int exitcount;

	step[0] = STEP;
	step[1] = STEP;
	step[2] = '\0';
	sign = rand() % 2;
	if (sign == 0)
		step[1] = 0;
	else
		step[0] = 0;
	sign = rand() % 2;
	if (g->player[0] < x && sign == 0)
	{
		step[0] = -STEP;
		step[1] = 0;
	}
	if (g->player[1] < y && sign == 1)
	{
		step[0] = 0;
		step[1] = -STEP;
	}
	if (!st_p(g, x + step[0], y + step[1]))
	{
		step[0] = 0;
		step[1] = 0;
	}
}

static void	enemymaker(t_vars *g, int *step)
{
	flipper(g, step, g->putin[0], g->putin[1]);
	(g->input)[g->putin[1] / TILE_SIZE][g->putin[0] / TILE_SIZE] = '0';
	g->putin[0] = g->putin[0] + step[0];
	g->putin[1] = g->putin[1] + step[1];
	(g->input)[g->putin[1] / TILE_SIZE][g->putin[0] / TILE_SIZE] = '8';
}

int	putin_run(t_vars *g)
{
	int	f;
	int	step[3];

	if (g->colore_shift == 8)
		end_the_game(g, 1);
	(g->par.putin_time)++;
	if (g->par.putin_time % 16 == 0)
		render_next_rays(g);
	if (g->shoot == 1 && g->par.putin_time % 16 == 0)
	{
		g->shoot = 0;
		g->simul_loop -= 2;
	}
	if (g->par.putin_time % 400 == 0 && g->putin[0] != -1 && g->putin[1] != -1)
		enemymaker(g, step);
	if (g->par.putin_time == 1000 && g->putin[0] != -1 && g->putin[1] != -1)
	{
		g->par.putin_time = 0;
	}
	return (0);
}
