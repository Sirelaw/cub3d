/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:23 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/23 17:29:32 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_line.h"
# include "ray_cast.h"

# define STEP 20
# define TILE_SIZE 64
# define MINI_SIZE 8
// Tile_size divided by mini_map_size
# define SCALE_TO_MINI 8
# define TILE_BIT 6

enum e_images
{
	FIG1 ,
	NONE ,
	WHITE_32 ,
	WHITE_8 ,
	NONE_32,
	NONE_8,
	PLAYER,
	FLOOR ,
	WALL ,
	BLACK,
	NIGERIA_64,
	HUNGARY_64,
	GERMANY_64,
	LOGO_42_64,
	HAND_GUN,
	BRICKWALL_DARK,
	BRICKWALL_GRAY,
	BRICKWALL_LIGHT,
	BRICKWALL_RED,
	PUTIN,
	IMAGE_COUNT
};

enum	e_keys
{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	LEFT_KEY = 123,
	RIGHT_KEY = 124	
};

typedef struct s_img
{
	void			*load;
	char			*path;
	int				width;
	int				height;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}	t_img;

typedef struct s_putin
{

	int		point_h[2];
	int		point_v[2];
	float	dist[2];
	int		putin_img_x;
	int		putin_img_y;
	float	putin_dist;
	int		putin_step;
	int		put_in;
	int		putin_time;
}				t_putin;

typedef struct s_vars
{
	t_img	image[IMAGE_COUNT];
	void	*mlx;
	void	*win;
	int		count;
	int		win_w;
	int		win_h;
	char	**map;
	void	*img;
	char	start_orientation;
	double	orient;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		player[2];
	int		putin[2];
	float	player_f[2];
	float	player_d[2];
	int		origin[2];
	char	**input;
	int		map_width;
	int		map_height;
	int		simul_loop;
	t_putin	par;
}				t_vars;

void	img_handler(t_vars *vars);

// ------- mlx  ----------
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		get_pixel(t_img *image, int x, int y);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		clean_destroy(t_vars *vars);

// ------- input ---------
void	input_rows_init_player(int argc, char **argv, t_vars *vars);
int		check_valid(char **input, t_vars *vars);
void	standardize_input(char **str_ptr, int *max_len);
void	ft_error(void);

// ------ ray --------

void	plotline(int x0_y0[2], int x1_y1[2], t_vars *vars, int color);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_field(t_vars *vars);
void	scale_image(t_vars *vars, t_img *image, double scale);
void	cast_rays(t_vars *vars);
void	init_look_up_down(t_vars *vars, t_ray* ray, float theta);
void	init_look_left_right(t_vars *vars, t_ray* ray, float theta);
int		render_next_rays(t_vars *vars);

// putin extras

int		putin_run(t_vars *g);

// -------- dev -------

void	print_str_arr(char **input);

#endif