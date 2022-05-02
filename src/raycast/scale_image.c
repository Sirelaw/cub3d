/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:48 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 15:41:32 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	scale_image(t_vars *vars, t_img *image, double scale)
{
	int		i;
	int		j;
	double	adjusted_lenght;
	int		color;

	i = 0;
	adjusted_lenght = scale * TILE_SIZE;
	vars->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	while (i < adjusted_lenght)
	{
		j = 0;
		while (j < adjusted_lenght)
		{
			my_mlx_pixel_put(vars, j, i, get_pixel(image,
					(j * TILE_SIZE) / adjusted_lenght,
					(i * TILE_SIZE) / adjusted_lenght));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
