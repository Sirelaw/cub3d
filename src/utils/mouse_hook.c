/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:28:28 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 15:37:34 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_player(int keycode, t_vars *vars)
{
	if (keycode == RIGHT_KEY)
		vars->orient += 0.2;
	else if (keycode == LEFT_KEY)
		vars->orient -= 0.2;
	if (vars->orient > 2 * M_PI)
		vars->orient -= 2 * M_PI;
	else if (vars->orient < 0)
		vars->orient += 2 * M_PI;
	vars->player_d[0] = cosf(vars->orient);
	vars->player_d[1] = sinf(vars->orient);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	if (vars->mouse < x / STEP)
		rotate_player(RIGHT_KEY, vars);
	else if (vars->mouse > x / STEP)
		rotate_player(LEFT_KEY, vars);
	vars->mouse = x / STEP;
	return (0);
}
