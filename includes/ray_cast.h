#ifndef RAY_CAST_H
# define RAY_CAST_H

#define	WHITE 0x00FFFFFF
#define	BLUE 0x0000FF
#define	RED 0xFF0000
#define GREEN 0x00FF00

typedef struct s_ray
{
	int 	mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	aTan;
	float	nTan;
	int		point_h[2];
	int		point_v[2];
	int		point[2];
	float	dist[2];
	float	distance;
	float	lineH;
	int		offset;
	int		type;
	int		door;
	int		door_flag;
}	t_ray;

#endif
