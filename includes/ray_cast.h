/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:01:59 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/04 19:01:23 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# define WHITE 0x00FFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00

enum e_images
{
	NO,
	SO,
	WE,
	EA,
	FIG1 ,
	NONE ,
	WHITE_32 ,
	WHITE_8 ,
	NONE_32,
	NONE_8,
	PLAYER,
	ENEMY,
	WALL ,
	BLACK,
	NIGERIA_64,
	HUNGARY_64,
	GERMANY_64,
	HAND_GUN,
	BRICKWALL_DARK,
	BRICKWALL_GRAY,
	BRICKWALL_LIGHT,
	BRICKWALL_RED,
	PUTIN64,
	PUTINS,
	WIN,
	LOST,
	FIRE,
	DOOR,
	IMAGE_COUNT
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

typedef struct s_ray
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	atan;
	float	ntan;
	int		point_h[2];
	int		point_v[2];
	int		point[2];
	float	dist[2];
	float	distance;
	float	lineh;
	int		offset;
	int		type;
	int		door[2];
	int		door_flag;
}	t_ray;

typedef struct s_putin
{
	int		put_point_x[1280];
	float	dist[2];
	int		putin_img_x;
	int		putin_img_y;
	float	putin_dist;
	int		putin_step;
	int		put_in;
	int		one_put;
	int		putin_time;
	int		hight;
	int		ofset_h;
	int		offset;
	int		one_side_flag;
	int		all_in;
}	t_putin;


int		smaller(int a, int b);
int		get_pixel(t_img *image, int x, int y);
float	get_dist(float ax, float ay, float bx, float by);



#endif
