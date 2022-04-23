#include "../../includes/cub3d.h"

float	get_dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by))));
}

static void	putin_ray_v(t_vars *vars, t_ray* ray)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
		&& ray->my < vars->map_height
		&& (vars->input)[ray->my][ray->mx] == '8')
	{
		vars->par.put_in = 1;
		vars->par.point_v[0] = ray->rx;
		vars->par.point_v[1] = ray->ry;
		vars->par.dist[1] = get_dist(vars->player[0], vars->player[1],
			vars->putin[0], vars->putin[1]);
	}
}

static void	look_left_right(t_vars *vars, t_ray* ray)
{
	ray->dof = 0;
	while (ray->dof < vars->map_width)
	{
		ray->mx = (int)(ray->rx) >> TILE_BIT;
		ray->my = (int)(ray->ry) >> TILE_BIT;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
			&& ray->my < vars->map_height
			&& (vars->input)[ray->my][ray->mx] == '1')
		{
			ray->point_v[0] = ray->rx;
			ray->point_v[1] = ray->ry;
			ray->dist[1] = get_dist(vars->player[0], vars->player[1], ray->rx, ray->ry);
			ray->dof = vars->map_width;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
		putin_ray_v(vars, ray);
	}
}

static void	putin_ray_h(t_vars *vars, t_ray* ray)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
		&& ray->my < vars->map_height
		&& (vars->input)[ray->my][ray->mx] == '8')
	{
		vars->par.put_in = 1;
		vars->par.point_h[0] = ray->rx;
		vars->par.point_h[1] = ray->ry;
		vars->par.dist[0] = get_dist(vars->player[0], vars->player[1],
			vars->putin[0], vars->putin[1]);
	}
}

static void	look_up_down(t_vars *vars, t_ray* ray)
{
	ray->dof = 0;
	while (ray->dof < vars->map_height)
	{
		ray->mx = (int)(ray->rx) >> TILE_BIT;
		ray->my = (int)(ray->ry) >> TILE_BIT;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map_width
			&& ray->my < vars->map_height
			&& (vars->input)[ray->my][ray->mx] == '1')
		{
			ray->point_h[0] = ray->rx;
			ray->point_h[1] = ray->ry;
			ray->dist[0] = get_dist(vars->player[0], vars->player[1],
				ray->rx, ray->ry);
			ray->dof = vars->map_height;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
		putin_ray_h(vars, ray);
	}
}

void	init_look_left_right(t_vars *vars, t_ray* ray, float theta)
{
	if (theta > M_PI_2 && theta < 3 * M_PI_2)
	{
		ray->rx = (((int)(vars->player[0]) >> TILE_BIT) << TILE_BIT) - 0.00015;
		ray->ry = (vars->player[0] - ray->rx) * ray->nTan + vars->player[1];
		ray->xo = -TILE_SIZE;
		ray->yo = -ray->xo * ray->nTan;
	}
	if (theta < M_PI_2 || theta > 3 * M_PI_2)
	{
		ray->rx = (((int)(vars->player[0]) >> TILE_BIT) << TILE_BIT) + TILE_SIZE;
		ray->ry = (vars->player[0] - ray->rx) * ray->nTan + vars->player[1];
		ray->xo = TILE_SIZE;
		ray->yo = -ray->xo * ray->nTan;
	}
	if (theta == M_PI_2 || theta == 3 * M_PI_2)
	{
		ray->rx = vars->player[0];
		ray->ry = vars->player[1];
		ray->dof = vars->map_width;
	}
	look_left_right(vars, ray);
}

void	init_look_up_down(t_vars *vars, t_ray* ray, float theta)
{
	if (theta > M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT) - 0.00015;
		ray->rx = (vars->player[1] - ray->ry) * ray->aTan + vars->player[0];
		ray->yo = -TILE_SIZE;
		ray->xo = -ray->yo * ray->aTan;
	}
	else if (theta < M_PI)
	{
		ray->ry = (((int)(vars->player[1]) >> TILE_BIT) << TILE_BIT) + TILE_SIZE;
		ray->rx = (vars->player[1] - ray->ry) * ray->aTan + vars->player[0];
		ray->yo = TILE_SIZE;
		ray->xo = -ray->yo * ray->aTan;
	}
	if (theta == 0 || theta == M_PI)
	{
		ray->rx = vars->player[0];
		ray->ry = vars->player[1];
		ray->dof = vars->map_height;
	}
	look_up_down(vars, ray);
}
