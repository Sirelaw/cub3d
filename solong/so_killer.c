#include "so_long.h"

void	my_killer(t_vars *g)
{
	if (((g->bh_x == g->fi_x && g->bh_y == g->fi_y)
	|| (g->b2_x == g->fi_x && g->b2_y == g->fi_y)) && g->collect != -1)
	{
		g->collect = -2;
		mlx_put_image_to_window(g->mlx, g->win, g->im[GOVER].l,
			(g->wi_x - 4) * 32, (g->he_y - 4) * 32);
		if (g->enemy > -1)
			g->enemy = -300;
		if (g->enemy == -1)
		{
			mlx_destroy_window(g->mlx, g->win);
			exit(EXIT_SUCCESS);
		}
	}
	if (g->collect == -1)
	{
		if (g->enemy > -1)
			g->enemy = -27000;
		if (g->enemy == -1)
		{
			mlx_destroy_window(g->mlx, g->win);
			exit(EXIT_SUCCESS);
		}
	}
}
