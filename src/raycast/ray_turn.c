/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:17 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/29 23:51:32 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void end_the_game(t_vars *vars, int suc)
{
	if (vars->colore_shift == -1)
	{
			// printf("FUCK YOU!!!\n");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[LOST].load, 50, 50);
		// sleep(10);
		// exit(EXIT_SUCCESS);

	}
	if (vars->colore_shift > KILL_SHOT)
	{
		// printf("FUCK YOU!!!\n");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[WIN].load, 50, 50);
	}
	// // mlx_destroy_image(game->mlx, game->img);
	// // mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	// // mlx_destroy_image(game->mlx, game->img);
	// if (suc == 1)
	// 	mlx_put_image_to_window(game->mlx, game->win, game->image[WIN].load, 50, 50);
	// if (suc == 0)
	// {

	// 	// printf("FUCK YOU!!!\n");
	// 	mlx_put_image_to_window(game->mlx, game->win, game->image[LOST].load, 50, 50);
	// }
	// // sleep(10);
	// // exit(EXIT_SUCCESS);
}

void	plot_line_angle(int start[2], float theta, float dist, t_vars *vars)
{
	int	point[2];
	int	new_point[2];

	point[0] = start[0] / SCALE_TO_MINI;
	point[1] = start[1] / SCALE_TO_MINI;
	new_point[0] = point[0] + (dist * cosf(theta));
	new_point[1] = point[1] + (dist * sinf(theta));
	plotline(point, new_point, vars, WHITE);
}

float	fix_fisheye_get_height(t_vars *vars, float distance, float angle_diff)
{
	float	lineH;

	if (angle_diff > 2 * M_PI)
		angle_diff -= 2 * M_PI;
	else if (angle_diff < 0)
		angle_diff += 2 * M_PI;
	distance = distance * cos(angle_diff);
	if (distance < 1)
		distance = 1;
	lineH = TILE_SIZE * WIN_HEIGHT / distance;
	return (lineH);
}

void	define_ray_parameters(t_vars *vars, t_ray *ray, float theta)
{
	ray->dist[0] = 1000000;
	ray->dist[1] = 1000000;
	vars->par.dist[0] = 1000000;
	vars->par.dist[1] = 1000000;
	ray->aTan = -1 / tan(theta);
	ray->nTan = -tan(theta);
	ray->door = 0;
}