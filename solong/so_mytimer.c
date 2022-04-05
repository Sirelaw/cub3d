#include "so_long.h"

static int	st_p(t_vars *g, int x, int y)
{
	if ((g->map)[y / g->sizer][x / g->sizer] == '1' ||
		(g->map)[y / g->sizer][x / g->sizer] == 'C' || (g->map)[y / g->sizer][x / g->sizer] == 'E')
		return (0);
	return (1);
}

static void	flipper_two(int *step, t_vars *g)
{
	if (step[0] == g->sizer && step[1] == 0)
	{
		step[0] = 0;
		step[1] = -g->sizer;
	}
	else if (step[0] == -g->sizer && step[1] == 0)
	{
		step[0] = 0;
		step[1] = g->sizer;
	}
	else if (step[0] == 0 && step[1] == g->sizer)
	{
		step[0] = g->sizer;
		step[1] = 0;
	}
	else if (step[0] == 0 && step[1] == -g->sizer)
	{
		step[0] = -g->sizer;
		step[1] = 0;
	}
	else
	{
		step[0] = g->sizer;
		step[1] = 0;
	}
}

static void	flipper(t_vars *g, int *step, int x, int y)
{
	int	sign;

	step[0] = g->sizer;
	step[1] = g->sizer;
	step[2] = '\0';
	sign = rand() % 2;
	if (sign == 0)
		step[1] = 0;
	else
		step[0] = 0;
	sign = rand() % 2;
	if (g->fi_x < x && sign == 0)
	{
		step[0] = -g->sizer;
		step[1] = 0;
	}
	if (g->fi_y < y && sign == 1)
	{
		step[1] = -g->sizer;
		step[0] = 0;
	}
	while (!st_p(g, x + step[0], y + step[1]))
		flipper_two(step, g);
}

static void	enemymaker(t_vars *g, int *step)
{
	flipper(g, step, g->bh_x, g->bh_y);
	mlx_put_image_to_window(g->mlx, g->win, g->im[FLOOR].l, g->bh_x, g->bh_y);
	g->bh_x = g->bh_x + step[0];
	g->bh_y = g->bh_y + step[1];
	mlx_put_image_to_window(g->mlx, g->win, g->im[BH1].l, g->bh_x, g->bh_y);
	flipper(g, step, g->b2_x, g->b2_y);
	mlx_put_image_to_window(g->mlx, g->win, g->im[FLOOR].l, g->b2_x, g->b2_y);
	g->b2_x = g->b2_x + step[0];
	g->b2_y = g->b2_y + step[1];
	mlx_put_image_to_window(g->mlx, g->win, g->im[BH1].l, g->b2_x, g->b2_y);
}

int	my_timer(t_vars *g)
{
	int	f;
	int	step[3];

	(g->enemy)++;
	// my_killer(g);
	f = 0;
	if ((g->enemy) % 2000 == 0 && g->bh_x != -1 && g->bh_y != -1)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		mlx_put_image_to_window(g->mlx, g->win, g->im[f].l, g->fi_x, g->fi_y);
		f = f + 5;
		mlx_put_image_to_window(g->mlx, g->win, g->im[f].l, g->bh_x, g->bh_y);
		mlx_put_image_to_window(g->mlx, g->win, g->im[f].l, g->b2_x, g->b2_y);
	}
	if (g->enemy == 1000 && g->bh_x != -1 && g->bh_y != -1)
		enemymaker(g, step);
	if (g->enemy == 3000 && g->bh_x != -1 && g->bh_y != -1)
	{
		f = 0;
		f = f + 5;
		mlx_put_image_to_window(g->mlx, g->win, g->im[f].l, g->bh_x, g->bh_y);
		mlx_put_image_to_window(g->mlx, g->win, g->im[f].l, g->b2_x, g->b2_y);
		g->enemy = 0;
	}
	return (0);
}
