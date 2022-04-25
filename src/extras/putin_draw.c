#include "../../includes/cub3d.h"

void	draw_putin(t_vars *vars, int i, int j, t_ray *ray)
{
	int		temp;
	int		hight;
	// int		colore;
	// int		n;
	// int		m;

	hight = (vars->image[PUTIN64].height * vars->win_h) / vars->par.putin_dist;
	temp = hight;
	// m = 0;
	// printf("%d my m:", vars->par.one_put);

	vars->par.put_point_x[vars->par.one_put] = i;
	vars->par.put_point_higth[vars->par.one_put] = hight;

	// while(temp--)
	// {
	// 	colore = get_pixel(&vars->image[PUTINS],
	// 			vars->par.one_put, (vars->par.offset++ * 64) / hight);
	// 	if (colore != 0xFFFFFF)
	// 	{
	// 		vars->par.points_colore[vars->par.one_put][m] = colore;
	// 		vars->par.points_x[vars->par.one_put][m] = i;
	// 		vars->par.points_y[vars->par.one_put][m] = j;
	// 		// my_mlx_pixel_put(vars, i, j , colore);
	// 	}
	// 	else
	// 		vars->par.points_colore[vars->par.one_put][m] = -1;
	// 	printf(" %d", m);
	// 	m++;
	// 	j++;
	// }
	// 	printf("\n");
}
