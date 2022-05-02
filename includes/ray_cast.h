/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:01:59 by ttokesi           #+#    #+#             */
/*   Updated: 2022/05/02 16:04:42 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# define WHITE 0x00FFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00

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

#endif
