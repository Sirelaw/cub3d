#include "so_long.h"

static int	st_p(t_vars *g, int x, int y)
{
	if ((g->map)[y / 65][x / 65] == 'C')
	{
		(g->collect)--;
		(g->map)[y / 65][x / 65] = '0';
	}
	if (g->collect == 0 && (g->map)[y / 65][x / 65] == 'E' && g->enemy > -1)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[WIN].l,
			(g->wi_x - 4) * 32 + 1, (g->he_y - 4) * 32 + 1);
		g->collect = -1;
	}
	if ((g->map)[y / 65][x / 65] == '1' || (g->map)[y / 65][x / 65] == 'E')
		return (0);
	return (1);
}

static int	move_up_down(t_vars *g, int key, int r)
{
	if (key == 126 || key == 13)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_y > 65 && st_p(g, g->fi_x, g->fi_y - 65))
			g->fi_y -= 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	if (key == 125 || key == 1)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_y < (g->he_y * 65) - 130 && st_p(g, g->fi_x, g->fi_y + 65))
			g->fi_y += 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	return (0);
}

static int	move_right_left(t_vars *g, int key, int r)
{
	if (key == 124 || key == 2)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_x < (g->wi_x * 65 ) - 130 && st_p(g, g->fi_x + 65, g->fi_y))
			g->fi_x += 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	if (key == 123 || key == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_x > 65 && st_p(g, g->fi_x - 65, g->fi_y))
			g->fi_x -= 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *g)
{
	int	fignum;

	fignum = rand() % 4;
	if (g->collect > -1)
	{
		if (keycode == 126 || keycode == 125 || keycode == 124
			|| keycode == 123)
			(g->count)++;
		if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
			(g->count)++;
		put_num_screen(g);
		if (keycode == 126 || keycode == 13)
			move_up_down(g, keycode, fignum);
		if (keycode == 125 || keycode == 1)
			move_up_down(g, keycode, fignum);
		if (keycode == 124 || keycode == 2)
			move_right_left(g, keycode, fignum);
		if (keycode == 123 || keycode == 0)
			move_right_left(g, keycode, fignum);
	}
	return (0);
}
