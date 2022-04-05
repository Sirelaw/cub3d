#include "so_long.h"

static void	my_error(int num)
{
	if (num == 3)
	{
		printf("Even a 5 years old can do better, too many steps you Lost!");
		exit(EXIT_SUCCESS);
	}
}

static void	cuted(t_vars *g)
{
	if (g->count < 10000)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count / 1000].l,
			105, (g->he_y) * 65 + 92 - 130);
		mlx_put_image_to_window(g->mlx, g->win,
			g->nu[(g->count / 100) % 10].l, 115, (g->he_y) * 65 + 92 - 130);
		mlx_put_image_to_window(g->mlx, g->win,
			g->nu[(g->count / 10) % 10].l, 125, (g->he_y) * 65 + 92 - 130);
		mlx_put_image_to_window(g->mlx, g->win,
			g->nu[g->count % 10].l, 135, (g->he_y) * 65 + 92 - 130);
	}
	else
		my_error(3);
}

void	put_num_screen(t_vars *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->im[COUNT].l, 30,
		(g->he_y) * 65 - 65);
	mlx_put_image_to_window(g->mlx, g->win, g->im[COUBG].l, 95,
		(g->he_y) * 65 - 65);
	if (g->count < 10)
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count].l, 105,
			(g->he_y) * 65 + 92 - 65 - 65);
	else if (g->count < 100)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count / 10].l, 105,
			(g->he_y) * 65 + 92 - 65 - 65);
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count % 10].l, 115,
			(g->he_y) * 65 + 92 - 65 - 65);
	}
	else if (g->count < 1000)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count / 100].l, 105,
			(g->he_y) * 65 + 92 - 65 - 65);
		mlx_put_image_to_window(g->mlx, g->win, g->nu[(g->count / 10) % 10].l,
			115, (g->he_y) * 65 + 92 - 65 - 65);
		mlx_put_image_to_window(g->mlx, g->win, g->nu[g->count % 10].l, 125,
			(g->he_y) * 65 + 92 - 65 - 65);
	}
	else
		cuted(g);
}
