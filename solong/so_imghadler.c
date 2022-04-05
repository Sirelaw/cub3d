#include "so_long.h"

static void	p_img(t_vars *g)
{
	g->im[FLOOR].p = "./img/floor.xpm";
	g->im[WALL].p = "./img/wall.xpm";
	g->im[FIG1].p = "./img/fig1.xpm";
	g->im[FIG2].p = "./img/fig3.xpm";
	g->im[FIG3].p = "./img/fig4.xpm";
	g->im[FIG4].p = "./img/fig2.xpm";
	g->im[MULI].p = "./img/muli.xpm";
	g->im[FMULI].p = "./img/fmuli.xpm";
	g->im[BH1].p = "./img/bh1.xpm";
	g->im[BH2].p = "./img/bh2.xpm";
	g->im[BH3].p = "./img/bh3.xpm";
	g->im[BH4].p = "./img/bh4.xpm";
	g->im[EVA].p = "./img/evas.xpm";
	g->im[EXP1].p = "./img/exp1.xpm";
	g->im[EXP2].p = "./img/exp2.xpm";
	g->im[COUNT].p = "./img/num/count.xpm";
	g->im[COUBG].p = "./img/num/bgnum.xpm";
	g->im[GOVER].p = "./img/gover.xpm";
	g->im[WIN].p = "./img/win.xpm";
}

static void	p_num(t_vars *g)
{
	g->nu[0].p = "./img/num/num0.xpm";
	g->nu[1].p = "./img/num/num1.xpm";
	g->nu[2].p = "./img/num/num2.xpm";
	g->nu[3].p = "./img/num/num3.xpm";
	g->nu[4].p = "./img/num/num4.xpm";
	g->nu[5].p = "./img/num/num5.xpm";
	g->nu[6].p = "./img/num/num6.xpm";
	g->nu[7].p = "./img/num/num7.xpm";
	g->nu[8].p = "./img/num/num8.xpm";
	g->nu[9].p = "./img/num/num9.xpm";
}

static void	load_num(t_vars *g)
{
	int	w;
	int	h;

	g->nu[0].l = mlx_xpm_file_to_image(g->mlx, g->nu[0].p, &w, &h);
	g->nu[1].l = mlx_xpm_file_to_image(g->mlx, g->nu[1].p, &w, &h);
	g->nu[2].l = mlx_xpm_file_to_image(g->mlx, g->nu[2].p, &w, &h);
	g->nu[3].l = mlx_xpm_file_to_image(g->mlx, g->nu[3].p, &w, &h);
	g->nu[4].l = mlx_xpm_file_to_image(g->mlx, g->nu[4].p, &w, &h);
	g->nu[5].l = mlx_xpm_file_to_image(g->mlx, g->nu[5].p, &w, &h);
	g->nu[6].l = mlx_xpm_file_to_image(g->mlx, g->nu[6].p, &w, &h);
	g->nu[7].l = mlx_xpm_file_to_image(g->mlx, g->nu[7].p, &w, &h);
	g->nu[8].l = mlx_xpm_file_to_image(g->mlx, g->nu[8].p, &w, &h);
	g->nu[9].l = mlx_xpm_file_to_image(g->mlx, g->nu[9].p, &w, &h);
}

static void	load_img(t_vars *g)
{
	int	w;
	int	h;

	g->im[FLOOR].l = mlx_xpm_file_to_image(g->mlx, g->im[FLOOR].p, &w, &h);
	g->im[WALL].l = mlx_xpm_file_to_image(g->mlx, g->im[WALL].p, &w, &h);
	g->im[FIG1].l = mlx_xpm_file_to_image(g->mlx, g->im[FIG1].p, &w, &h);
	g->im[FIG2].l = mlx_xpm_file_to_image(g->mlx, g->im[FIG2].p, &w, &h);
	g->im[FIG3].l = mlx_xpm_file_to_image(g->mlx, g->im[FIG3].p, &w, &h);
	g->im[FIG4].l = mlx_xpm_file_to_image(g->mlx, g->im[FIG4].p, &w, &h);
	g->im[MULI].l = mlx_xpm_file_to_image(g->mlx, g->im[MULI].p, &w, &h);
	g->im[FMULI].l = mlx_xpm_file_to_image(g->mlx, g->im[FMULI].p, &w, &h);
	g->im[BH1].l = mlx_xpm_file_to_image(g->mlx, g->im[BH1].p, &w, &h);
	g->im[BH2].l = mlx_xpm_file_to_image(g->mlx, g->im[BH2].p, &w, &h);
	g->im[BH3].l = mlx_xpm_file_to_image(g->mlx, g->im[BH3].p, &w, &h);
	g->im[BH4].l = mlx_xpm_file_to_image(g->mlx, g->im[BH4].p, &w, &h);
	g->im[EXP1].l = mlx_xpm_file_to_image(g->mlx, g->im[EXP1].p, &w, &h);
	g->im[EXP2].l = mlx_xpm_file_to_image(g->mlx, g->im[EXP2].p, &w, &h);
	g->im[EVA].l = mlx_xpm_file_to_image(g->mlx, g->im[EVA].p, &w, &h);
	g->im[COUNT].l = mlx_xpm_file_to_image(g->mlx, g->im[COUNT].p, &w, &h);
	g->im[COUBG].l = mlx_xpm_file_to_image(g->mlx, g->im[COUBG].p, &w, &h);
	g->im[GOVER].l = mlx_xpm_file_to_image(g->mlx, g->im[GOVER].p, &w, &h);
	g->im[WIN].l = mlx_xpm_file_to_image(g->mlx, g->im[WIN].p, &w, &h);
}

void	img_handler(t_vars *game)
{
	p_img(game);
	load_img(game);
	p_num(game);
	load_num(game);
}
