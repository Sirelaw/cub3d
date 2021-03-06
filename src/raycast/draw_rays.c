/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:06:25 by oipadeol          #+#    #+#             */
/*   Updated: 2022/05/04 18:37:03 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_field_norm(t_vars *vars)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] == '1' && i * MINI_SIZE < vars->player[1]
				/ SCALE_TO_MINI + 50
				&& i * MINI_SIZE > vars->player[1] / SCALE_TO_MINI - 50
				&& j * MINI_SIZE < vars->player[0] / SCALE_TO_MINI + 50
				&& j * MINI_SIZE > vars->player[0] / SCALE_TO_MINI - 50)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->image[WHITE_8].load,
					j * MINI_SIZE, i * MINI_SIZE);
			j++;
		}
		i++;
	}
}

void	draw_field(t_vars *vars)
{
	draw_field_norm(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
		vars->player[0] / SCALE_TO_MINI, vars->player[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[ENEMY].load,
		vars->putin[0] / SCALE_TO_MINI, vars->putin[1] / SCALE_TO_MINI);
	if (vars->shoot == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[FIRE].load,
			WIN_WIDTH - 302 + (vars->simul_loop % 4) * 10,
			WIN_HEIGHT - 302 + (vars->simul_loop % 4) * 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].load,
		WIN_WIDTH - 232 + (vars->simul_loop % 4) * 10, WIN_HEIGHT - 232
		+ (vars->simul_loop % 4) * 10);
	end_the_game(vars, 1);
}

void	draw_line(t_vars *vars, int i, t_ray *ray)
{
	int	fill;
	int	j;
	int	t;

	j = 0;
	ray->offset = 0;
	fill = WIN_HEIGHT - ray->lineh;
	fill /= 2;
	if (fill < 0)
		ray->offset = -1 * fill;
	vars->par.offset = ray->offset;
	while (j < fill)
		my_mlx_pixel_put(vars, i, j++, vars->ceiling_color);
	t = j;
	draw_wall(vars, i, &j, ray);
	while (j < WIN_HEIGHT)
		my_mlx_pixel_put(vars, i, j++, vars->floor_color);
	draw_putin(vars, i, ray);
}

static int	draw_wall_norm(t_vars *vars, t_ray *ray)
{
	int		image;

	if (ray->type == 0 && ray->point[1] >= vars->player[1])
		image = SO;
	else if (ray->type == 0)
		image = NO;
	if (ray->type == 1 && ray->point[0] >= vars->player[0])
		image = WE;
	else if (ray->type == 1)
		image = EA;
	if (ray->door[ray->type])
		image = DOOR;
	return (image);
}

void	draw_wall(t_vars *vars, int i, int *j, t_ray *ray)
{
	int		temp;
	int		image;

	temp = ray->lineh;
	image = draw_wall_norm(vars, ray);
	while (temp-- && *j < WIN_HEIGHT)
	{
		my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
				ray->point[ray->type] % vars->image[image].width,
				(ray->offset++ *vars->image[image].height) / ray->lineh));
		(*j)++;
	}
}
