/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:23 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/05 22:53:12 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

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
	char	**input;
}t_vars;

char	**input_rows(int argc, char **argv, char *start_orientation);
int		check_valid(char **input, char *start_orientation);
void	ft_error(void);

#endif