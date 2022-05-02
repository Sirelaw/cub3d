/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:37:40 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 15:40:01 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if ((x >= WIN_WIDTH) || (y >= WIN_HEIGHT) || (x < 0) || (y < 0))
		return ;
	dst = vars->addr + (y * vars->line_lenght
			+ x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *image, int x, int y)
{
	char	*color;

	color = image->addr + (y * image->line_lenght
			+ x * (image->bits_per_pixel / 8));
	return (*(unsigned int *) color);
}

int	render_next_rays(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	cast_rays(vars);
	return (0);
}

void	free_all(t_vars *vars)
{
	char	**input;
	int		i;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
	free(vars->image[NO].path);
	free(vars->image[SO].path);
	free(vars->image[EA].path);
	free(vars->image[WE].path);
}

int	clean_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_all(vars);
	exit(EXIT_SUCCESS);
}
