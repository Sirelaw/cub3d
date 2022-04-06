#include "../../includes/cub3d.h"

static int	absolute(int n)
{
	if ((n < 0) && (n != INT_MIN))
		return (-1 * n);
	else
		return (n);
}

static void plotLineLow(int x, int y, int x1, int y1, t_vars *game)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;

	dx = x1 - x;
	dy = y1 - y;
	yi = 1;
	D = (2 * dy) - dx;
	if (dy < 0)
	{	
	    yi = -1;
	    dy = -dy;	
	}
	while (x <= x1)
	{
		my_mlx_pixel_put(game, x, y,0x0000FF);
		if (D > 0)
		{
	        y = y + yi;
	        D = D + (2 * (dy - dx));		
		}
		else
	        D = D + (2 * dy);
		x++;
	}
}

static void plotLineHigh(int x, int y, int x1, int y1, t_vars *game)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	
	dx = x1 - x;
	dy = y1 - y;
	xi = 1;
	D = (2 * dx) - dy;
	if (dx < 0)
	{	
	    xi = -1;
	    dx = -dx;	
	}
	while (y <= y1)
	{
		my_mlx_pixel_put(game, x, y,0x0000FF);
		if (D > 0)
		{
	        x = x + xi;
	        D = D + (2 * (dx - dy));		
		}
		else
	        D = D + (2 * dx);
		y++;
	}
}

void	plotLine(int x0, int y0, int x1, int y1, t_vars *game)
{
    if (absolute(y1 - y0) < absolute(x1 - x0))
	{
        if (x0 > x1)
            plotLineLow(x1, y1, x0, y0, game);
        else
            plotLineLow(x0, y0, x1, y1, game);
	}
    else
	{
        if (y0 > y1)
            plotLineHigh(x1, y1, x0, y0, game);
        else
            plotLineHigh(x0, y0, x1, y1, game);
	}
}