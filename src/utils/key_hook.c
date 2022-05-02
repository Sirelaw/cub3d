/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:26:47 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 15:40:22 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_end(t_vars *vars)
{
	int	dist;

	dist = get_dist(vars->player[0], vars->player[1],
			vars->putin[0], vars->putin[1]);
	if (dist < 1 * TILE_SIZE)
	{
		vars->colore_shift = -1;
		end_the_game(vars, 1);
	}
}

static void	check_valid_position(float temp[2], t_vars *vars)
{
	if ((vars->input)[(int)temp[1] >> TILE_BIT][(int)temp[0] >> TILE_BIT]
		!= '1')
	{
		if ((vars->input)[(int)temp[1] >> TILE_BIT][(int)temp[0] >> TILE_BIT]
		== 'D')
		{
			if (!vars->open_door)
				return ;
			vars->last_door[0] = (int)temp[0] >> TILE_BIT;
			vars->last_door[1] = (int)temp[1] >> TILE_BIT;
			(vars->input)[(int)temp[1] >> TILE_BIT][(int)temp[0] >> TILE_BIT]
				= '0';
		}
		vars->player_f[0] = temp[0];
		vars->player_f[1] = temp[1];
		vars->player[0] = temp[0];
		vars->player[1] = temp[1];
		vars->simul_loop++;
		vars->simul_loop = vars->simul_loop & 15;
	}
	check_end(vars);
}

void	move_image(int keycode, t_vars *vars)
{
	float	temp[2];

	temp[0] = vars->player_f[0];
	temp[1] = vars->player_f[1];
	if (keycode == A_KEY)
	{
		temp[0] += STEP * vars->player_d[1];
		temp[1] -= STEP * vars->player_d[0];
	}
	else if (keycode == D_KEY)
	{
		temp[0] -= STEP * vars->player_d[1];
		temp[1] += STEP * vars->player_d[0];
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		temp[0] -= STEP * vars->player_d[0];
		temp[1] -= STEP * vars->player_d[1];
	}
	else if (keycode == W_KEY || keycode == UP_KEY)
	{
		temp[0] += STEP * vars->player_d[0];
		temp[1] += STEP * vars->player_d[1];
	}
	check_valid_position(temp, vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		clean_destroy(vars);
	if (keycode == 123 || keycode == 124)
		rotate_player(keycode, vars);
	else if (keycode == A_KEY || keycode == D_KEY || keycode == S_KEY
		|| keycode == W_KEY || keycode == UP_KEY || keycode == DOWN_KEY)
		move_image(keycode, vars);
	else if (keycode == 257 || keycode == 258)
	{
		if (vars->shoot == 0)
		{
			vars->shoot = 1;
			vars->simul_loop += 2;
		}
	}
	else if (keycode == SPACE_KEY)
		vars->open_door = 1;
	return (0);
}
