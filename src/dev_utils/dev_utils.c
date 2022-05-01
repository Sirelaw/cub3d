#include "../includes/cub3d.h"

#define PRINT_HERE (printf("Here\n"))

void	print_str_arr(char **input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		printf("%s\n", input[i]);
		i++;
	}
}

// void	cast_p_rays(t_vars *g)
// {
// 	float putin_dist;
// 	float line_h_and_w;
// 	float max_angle;
// 	float slop_orient;
// 	float slop_player_putin;

// 	g->par.putin_dist_ii = get_dist(g->player[0], g->player[1], g->putin[0], g->putin[1]);
// 	g->par.line_h_and_w = TILE_SIZE * g->win_h / putin_dist;
// 	g->par.max_angle = atan((g->par.line_h_and_w / 2) / g->par.putin_dist_ii);

// 	//relative angle compare to player orient
// 	slop_player_putin = (g->putin[1] - g->player[1]) / (g->putin[0] - g->player[0]);
// 	slop_orient = tan(g->orient);
// 	if (slop_orient > slop_player_putin) // 
// 	float ori_put_ang;
// 	ori_put_ang = g->orient - atan(slop_player_putin);
// }