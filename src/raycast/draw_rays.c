/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:06:25 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/29 19:34:38 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_mini_map(t_vars *vars)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		j = 0;
		while(input[i][j])
		{
			if (input[i][j] == '1' && i * MINI_SIZE < vars->player[1]
				/ SCALE_TO_MINI + 50000
				&& i * MINI_SIZE > vars->player[1] / SCALE_TO_MINI - 50000
				&& j * MINI_SIZE < vars->player[0] / SCALE_TO_MINI + 50000
				&& j * MINI_SIZE > vars->player[0] / SCALE_TO_MINI - 50000)
				mlx_put_image_to_window(vars->mlx, vars->win,
				vars->image[WHITE_8].load,
				j * MINI_SIZE, i * MINI_SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->player[0] / SCALE_TO_MINI, vars->player[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->putin[0] / SCALE_TO_MINI, vars->putin[1] / SCALE_TO_MINI);
	if (vars->shoot == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[FIRE].load, vars->win_w - 302 + (vars->simul_loop % 4) * 10, vars->win_h - 302 + (vars->simul_loop % 4) * 10);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].load,
		vars->win_w - 232 + (vars->simul_loop % 4) * 10 , vars->win_h - 232 + (vars->simul_loop % 4) * 10);
	if (vars->this_ends != -1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[LOST].load, 50, 50);
		// sleep(10);
		// exit(EXIT_SUCCESS);

	}
	if (vars->colore_shift > KILL_SHOT)
	{
		// printf("FUCK YOU!!!\n");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image[WIN].load, 50, 50);
	}
		// end_the_game(vars, 1);
}

void	draw_line(t_vars *vars, int i, t_ray *ray)
{
	int	fill;
	int	j;
	int	k;
	int	l;

	j = 0;
	// k = 0;
	ray->offset = 0;
	fill = vars->win_h - ray->lineH;
	fill /= 2;
	if (fill < 0)
		ray->offset = -1 * fill;
	vars->par.offset = ray->offset;
	while (j < fill)
		my_mlx_pixel_put(vars, i, j++, vars->ceiling_color);
	int t = j;
	draw_wall(vars, i, &j, ray);
	while (j < vars->win_h)
	{
		// if (i % 64 == 0)
		// 	my_mlx_pixel_put(vars, i, j++, 0x000000);
		// else if (j % 64 == 0)
		// 	my_mlx_pixel_put(vars, i, j++, 0x000000);
		// else
			my_mlx_pixel_put(vars, i, j++, vars->floor_color);

	}
	// printf("%d \n", vars->par.put_in);
	if (vars->par.put_in == 1/*  &&  vars->par.one_put < 64 */)
	{

		// in some cases teh rays don't hit putin so this never runs....
		// why is not hitting by the ray?? 
		// go over exchange functions make them norm ready and step by step check the flow
		// why does it skip some putin, why isnt catching it???
		
		vars->par.hight = (vars->image[PUTINS].height * vars->win_h) / vars->par.putin_dist;
		vars->par.ofset_h = vars->par.hight / TILE_SIZE;
		draw_putin(vars, i, t, ray);
		vars->par.one_put++;
	}
}

void	draw_wall(t_vars *vars, int i, int *j, t_ray *ray)
{
	int		temp;
	int		image;

	temp = ray->lineH;
	if (ray->type == 0 && ray->point[1] >= vars->player[1])
		image = SO;
	else if (ray->type == 0)
		image = NO;
	if (ray->type == 1 && ray->point[0] >= vars->player[0])
		image = WE;
	else if (ray->type == 1)
		image = EA;
	while(temp-- && *j < vars->win_h)
	{		
		if (ray->door && vars->door_flag != -1)
		{
			printf("reset flag	%d	%d	%d\n", i, ray->point[ray->type], ray->point[ray->type] % vars->image[DOOR].width);
			if (vars->door_flag == 0)
				vars->door_flag = ray->point[ray->type] % vars->image[DOOR].width;
			if (ray->point[ray->type] % vars->image[DOOR].width == vars->image[DOOR].width - 1 
				&& ray->point[ray->type] % vars->image[DOOR].width != vars->door_flag)
			{
				printf("Here\n");
				vars->door_flag = -1;
				// exit(0);
			}
			image = DOOR;
		}
		// if (ray->door && vars->door_flag != -1)
		// {
		// 	if (ray->point[ray->type] % vars->image[DOOR].width == vars->image[DOOR].width - 1 && vars->door_flag == 1)
		// 	{
		// 		printf("set flag	%d	%d	%d\n", i, ray->point[ray->type], ray->point[ray->type] % vars->image[DOOR].width);
		// 		vars->door_flag = -1;
		// 	}
		// }
		my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
			ray->point[ray->type] % vars->image[image].width,
			(ray->offset++ * vars->image[image].height) / ray->lineH));
		(*j)++;
	}
}
