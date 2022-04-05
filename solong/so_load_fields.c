#include "so_long.h"

static void	side_two(t_vars *g, char *temp2, int i, int j)
{
	if (*temp2 == 'P' && g->check == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, j * 65, i * 65);
		g->fi_x = j * 65;
		g->fi_y = i * 65;
		g->check = 1;
	}
	else if (*temp2 == 'P' && g->check == 1)
	{
		g->bh_x = j * 65;
		g->bh_y = i * 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[6].l, g->bh_x, g->bh_y);
		g->check = 2;
	}
	else if (*temp2 == 'P' && g->check == 2)
	{
		g->b2_x = j * 65;
		g->b2_y = i * 65;
		mlx_put_image_to_window(g->mlx, g->win, g->im[7].l, g->bh_x, g->bh_y);
		g->check = 3;
	}
}

static void	side_one(t_vars *g, char *temp2, int i, int j)
{
	if (*temp2 == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->im[WALL].l, j * 65, i * 65);
	if (*temp2 == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * 65, i * 65);
	if (*temp2 == '0')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, j * 65, i * 65);
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->bh_x = j * 65;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->bh_y = i * 65;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->b2_x = j * 65;
		if (g->check != 3 && g->check != 2 && g->check == 1)
			g->b2_y = i * 65;
	}
	if (*temp2 == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[EVA].l, j * 65, i * 65);
		(g->collect)++;
	}
	if (*temp2 == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->im[MULI].l, j * 65, i * 65);
	side_two(g, temp2, i, j);
}

void	load_fields(t_map *head, t_vars *g)
{
	t_map	*temp;
	char	*temp2;
	int		i;
	int		j;

	g->map = malloc(g->he_y * sizeof(char *));
	if (head == NULL)
		return ;
	temp = head;
	i = 0;
	j = 0;
	while (temp != NULL && i < g->he_y)
	{
		temp2 = temp->content;
		(g->map)[i] = temp2;
		j = 0;
		while (temp2 && j < g->wi_x)
		{
			side_one(g, temp2, i, j);
			temp2++;
			j++;
		}
		temp = temp->next;
		i++;
	}
}
