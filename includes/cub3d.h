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
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		map_w;
	int		map_l;
	char	**input;
}t_vars;

char	**input_rows(int argc, char **argv);
int		check_valid(char **input);
void	ft_error(void);


#endif