#include "so_long.h"

static int	close1(int keycode, t_vars *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	close12(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	set_startvalues(t_vars *game, int lines, int rows)
{
	game->enemy = 0;
	game->count = 0;
	game->fi_x = 65;
	game->fi_y = 65;
	game->wi_x = rows;
	game->he_y = lines;
	game->collect = 0;
	game->check = 0;
	game->bh_x = -1;
	game->bh_y = -1;
	game->b2_x = -1;
	game->b2_y = -1;
}

void	game_starter(t_map *head, int lines, int rows)
{
	t_vars	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, rows * 65, lines * 65,
			"42 Surviver Game");
	mlx_hook(game.win, 2, 1L << 2, close1, &game);
	mlx_hook(game.win, 17, 1L << 17, close12, &game);
	img_handler(&game);
	set_startvalues(&game, lines, rows);
	mlx_key_hook(game.win, key_hook, &game);
	load_fields(head, &game);
	mlx_loop_hook(game.mlx, my_timer, &game);
	mlx_loop(game.mlx);
}
