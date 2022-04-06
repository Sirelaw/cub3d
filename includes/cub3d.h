/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:23 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/06 14:36:53 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	start_orientation;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		player[2];
	char	**input;
}t_vars;

void	input_rows(int argc, char **argv, t_vars *vars);
int		check_valid(char **input, t_vars *vars);
void	ft_error(void);

#endif