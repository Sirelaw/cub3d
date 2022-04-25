#include "../../includes/cub3d.h"

void plot_line_angle(int start[2], float theta, float dist, t_vars *vars)
{
	int	point[2];
	int	new_point[2];

	point[0] = start[0] / SCALE_TO_MINI;
	point[1] = start[1] / SCALE_TO_MINI;
	new_point[0] = point[0] + (dist * cosf(theta));
	new_point[1] = point[1] + (dist * sinf(theta));
	plotline(point, new_point, vars, WHITE);
}

float	fix_fisheye_get_height(t_vars *vars, float distance, float angle_diff)
{
	float	lineH;

	if (angle_diff > 2 * M_PI)
		angle_diff -= 2 * M_PI;
	else if (angle_diff < 0)
		angle_diff += 2 * M_PI;
	distance = distance * cos(angle_diff);
	if (distance < 1)
		distance = 1;
	lineH = TILE_SIZE * vars->win_h / distance;
	return (lineH);
}

void	draw_wall(t_vars *vars, int i, int *j, t_ray *ray)
{
	int		k;
	int		l;
	int		temp;
	int		image;

	temp = ray->lineH;
	k = 0;
	if (ray->type == 0)
	{
		if (ray->point[1] >= vars->player[1])
			image = SO;
		else
			image = NO;
	}
	else
	{
		if (ray->point[0] >= vars->player[0])
			image = WE;
		else
			image = EA;
	}
	while(temp-- && *j < vars->win_h)
	{
		if (ray->type == 0)
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
				ray->point[0] % vars->image[image].width,
				(ray->offset++ * vars->image[image].height) / ray->lineH));
		else
			my_mlx_pixel_put(vars, i, *j, get_pixel(&vars->image[image],
				ray->point[1] % vars->image[image].width,
				(ray->offset++ * vars->image[image].height) / ray->lineH));
		(*j)++;
	}
}

void	draw_line(t_vars *vars, int i, t_ray *ray)
{
	int	fill;
	int	j;
	int	k;
	int	l;

	j = 0;
	// k = 0;
	ray->offset = 0;
	fill = vars->win_h - ray->lineH;
	fill /= 2;
	if (fill < 0)
		ray->offset = -1 * fill;
	vars->par.offset = ray->offset;
	while (j < fill)
		my_mlx_pixel_put(vars, i, j++, vars->ceiling_color);
	int t = j;
	draw_wall(vars, i, &j, ray);
	while (j < vars->win_h)
		my_mlx_pixel_put(vars, i, j++, vars->floor_color);
	// printf("%d \n", vars->par.put_in);
	if (vars->par.put_in == 1 &&  vars->par.one_put < 21)
	{
		// in some cases teh rays don't hit putin so this never runs....
		// why is not hitting by the ray?? 
		vars->par.hight = (vars->image[PUTIN64].height * vars->win_h) / vars->par.putin_dist;
		vars->par.ofset_h = vars->par.hight / TILE_SIZE;
		draw_putin(vars, i, t, ray);
		vars->par.one_put++;
	}
}

static void	cast_ray(t_vars *vars, float theta, int i)
{
	t_ray	ray;
	int		color;

	ray.dist[0] = 1000000;
	ray.dist[1] = 1000000;
	vars->par.dist[0] = 1000000;
	vars->par.dist[1] = 1000000;
	ray.aTan = -1 / tan(theta);
	ray.nTan = -tan(theta);
	init_look_up_down(vars, &ray, theta);
	init_look_left_right(vars, &ray, theta);
	if (ray.dist[0] < ray.dist[1])
	{
		ray.distance = ray.dist[0];
		ray.point[0] = ray.point_h[0];
		ray.point[1] = ray.point_h[1];
		color = 0xd617e8;
		ray.type = 0;
	}
	else
	{
		ray.distance = ray.dist[1];
		ray.point[0] = ray.point_v[0];
		ray.point[1] = ray.point_v[1];
		color = 0xe8d617;
		ray.type = 1;
	}
	if (vars->par.dist[0] < vars->par.dist[1])
	{
		vars->par.putin_dist = vars->par.dist[0];
		vars->par.type = 1;
	}
	else
	{
		vars->par.type = 0;
		vars->par.putin_dist = vars->par.dist[1];
	}

	ray.lineH = fix_fisheye_get_height(vars, ray.distance, vars->orient - theta);
	plot_line_angle(vars->player, theta, 5, vars);
	if (vars->par.put_in == 1)
	{
		vars->par.putin_img_x = i;
		vars->par.putin_img_y = vars->win_h / 2 - ray.lineH / 2;
	}
	draw_line(vars, i, &ray);
}

void draw_putin_arays(t_vars *vars)
{
	int i;
	int j;
	int colore;
	double	adj;

	i = 0;
	adj = vars->par.hight - 50;
	adj = 64;
	while (i < adj)
	{
		j = 0;
		while (j < adj)
		{
			if (vars->par.put_point_x[(int)((i * TILE_SIZE) / adj)] != -1)
			{
				colore = get_pixel(&vars->image[PUTIN64], (i * TILE_SIZE) / adj, (j * TILE_SIZE) / adj);
				if (colore != 0xFFFFFF)
					my_mlx_pixel_put(vars, vars->par.put_point_x[i],  450 + j, colore);
			}
			// colore = vars->par.points_colore[i][j];
			// if (colore != -1)
			// 	my_mlx_pixel_put(vars, vars->par.points_x[i][j] + 64, vars->par.points_y[i][j] , colore);
			j++;
		}
		i++;
	}
}

void fill_putin_arays(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		vars->par.put_point_higth[i] = -1;
		vars->par.put_point_x[i] = -1;
		while (j < 64)
		{
			vars->par.points_x[i][j] = -1;
			vars->par.points_y[i][j] = -1;
			vars->par.points_colore[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	cast_rays(t_vars *vars)
{
	int		i;
	float	dtheta;
	float	theta;
	int		point[2];

	i = 0;
	theta = vars->orient - M_PI / 6;
	dtheta = (M_PI / 3.0) / vars->win_w;
	vars->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	// printf("---------------------cycle---------------------\n");
	vars->par.one_put = 0;
	fill_putin_arays(vars);
	while (i++ < vars->win_w)
	{
		vars->par.put_in = 0;
		theta += dtheta;
		if (theta > 2 * M_PI)
			theta -= 2 * M_PI;
		else if (theta < 0)
			theta += 2 * M_PI;
		cast_ray(vars, theta, i);
	}
	draw_putin_arays(vars);
	// printf("x:%d y:%d\n", vars->putin[0], vars->putin[1]);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	
	// if (vars->par.put_in == 1)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PUTIN].load,
	// 		vars->par.putin_img_x , vars->par.putin_img_y);
	draw_field(vars);
}

void	draw_field(t_vars *vars)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = vars->input;
	while (input[i])
	{
		j = 0;
		while(input[i][j])
		{
			if (input[i][j] == '1' && i * MINI_SIZE < vars->player[1]
				/ SCALE_TO_MINI + 50000
				&& i * MINI_SIZE > vars->player[1] / SCALE_TO_MINI - 50000
				&& j * MINI_SIZE < vars->player[0] / SCALE_TO_MINI + 50000
				&& j * MINI_SIZE > vars->player[0] / SCALE_TO_MINI - 50000)
				mlx_put_image_to_window(vars->mlx, vars->win,
				vars->image[WHITE_8].load,
				j * MINI_SIZE, i * MINI_SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->player[0] / SCALE_TO_MINI, vars->player[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[PLAYER].load,
	vars->putin[0] / SCALE_TO_MINI, vars->putin[1] / SCALE_TO_MINI);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image[HAND_GUN].load,
		vars->win_w - 232 + (vars->simul_loop % 4) * 10 , vars->win_h - 232 + (vars->simul_loop % 4) * 10);
}
