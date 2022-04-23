/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:53:35 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/22 19:59:01 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	p_img(t_vars *vars)
{
	vars->image[FIG1].path = "./img/fig1.xpm";
	vars->image[NONE].path = "./img/none.xpm";
	vars->image[WHITE_32].path = "./img/white_32.xpm";
	vars->image[WHITE_8].path = "./img/white_8.xpm";
	vars->image[NONE_32].path = "./img/none_32.xpm";
	vars->image[NONE_8].path = "./img/none_8.xpm";
	vars->image[PLAYER].path = "./img/player_4.xpm";
	vars->image[FLOOR].path = "./img/floor.xpm";
	vars->image[WALL].path = "./img/wall.xpm";
	vars->image[BLACK].path = "./img/black.xpm";
	vars->image[NIGERIA_64].path = "./img/Nigeria_64.xpm";
	vars->image[HUNGARY_64].path = "./img/Hungary_64.xpm";
	vars->image[GERMANY_64].path = "./img/Germany_64.xpm";
	vars->image[LOGO_42_64].path = "./img/42logo_64.xpm";
	vars->image[HAND_GUN].path = "./img/hand-with-gun.xpm";
	vars->image[BRICKWALL_DARK].path = "./img/brickwall_dark.xpm";
	vars->image[BRICKWALL_GRAY].path = "./img/brickwall_gray.xpm";
	vars->image[BRICKWALL_LIGHT].path = "./img/brickwall_ligth.xpm";
	vars->image[BRICKWALL_RED].path = "./img/brickwall_red.xpm";
	vars->image[PUTIN].path = "./img/v_putin.xpm";
}

static void	load_img(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < IMAGE_COUNT)
	{
		vars->image[i].load = mlx_xpm_file_to_image(vars->mlx,
					vars->image[i].path,
					&vars->image[i].width, &vars->image[i].height);
		if (vars->image[i].load == NULL)
		{
			printf("Could not open %s\n", vars->image[i].path);
			ft_error();
		}
		vars->image[i].addr = mlx_get_data_addr(vars->image[i].load,
			&(vars->image[i].bits_per_pixel), &(vars->image[i].line_lenght),
			&(vars->image[i].endian));
		i++;
	}
}

void	img_handler(t_vars *game)
{
	p_img(game);
	load_img(game);
}
