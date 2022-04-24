#include "../../includes/cub3d.h"

void	draw_putin(t_vars *vars, int i, int j, t_ray *ray)
{
	int		temp;
	int		hight;
	int		k;
	int colore;

	k = 0;
	hight = (vars->image[PUTIN64].height * vars->win_h) / vars->par.putin_dist;
	temp = hight;
	while(temp--)
	{
		colore = get_pixel(&vars->image[PUTIN64],
				vars->par.one_put, (vars->par.offset++ * 64) / hight);
		if (colore != 0xFFFFFF)
			my_mlx_pixel_put(vars, i, j , colore);
		j++;
	}
}
