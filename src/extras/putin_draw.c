#include "../../includes/cub3d.h"

void	draw_putin(t_vars *vars, int i, int j, t_ray *ray)
{
	int		temp;
	int		hight;
	// int		colore;
	// int		n;
	// int		m;

	// hight = (vars->image[PUTIN64].height * vars->win_h) / vars->par.putin_dist;
	// temp = hight;
	// m = 0;
	// printf("%d my m:", vars->par.one_put);

	vars->par.put_point_x[vars->par.one_put] = i;
	// vars->par.put_point_higth[vars->par.one_put] = hight;

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

static int	colore_shift(int color, int scale)
{
	int		a;
	int		r;
	int		g;
	int		b;
	float	rdecimal; 

	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	rdecimal = r / 255; 
	rdecimal = r * scale; 
	r = (int)(rdecimal * 255); 
	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

static void draw_putin_arays_norm(t_vars *vars, int colore, int i, int j)
{
	if (vars->colore_shift > 0)
		colore = colore_shift(colore, vars->colore_shift);
	my_mlx_pixel_put(vars, vars->par.put_point_x[i],
		POSITION_PUTIN_Y + j, colore);
}

void draw_putin_arays(t_vars *vars)
{
	int i;
	int j;
	int colore;
	double	adj;

	i = 0;
	adj = vars->par.hight - RELATIVE_SIZE_PUTIN;
	while (i < adj)
	{
		j = 0;
		while (j < adj)
		{
			if (vars->par.put_point_x[(int)((i * TILE_SIZE) / adj)] != -1)
			{
				colore = get_pixel(&vars->image[PUTINS],
					(i * TILE_SIZE) / adj, (j * TILE_SIZE) / adj);
				if (colore != 0xFFFFFF)
					draw_putin_arays_norm(vars, colore, i , j);
			}
			j++;
		}
		i++;
	}
}
