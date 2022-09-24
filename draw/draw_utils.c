#include "../cub3D.h"

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}

int	rgb_to_int(int opacity, int red, int green, int blue)
{
	return ((opacity * 16777216) + (red * 65536) + (green * 256) + blue);
}

void	shortdistance(double *x1, double *y1, t_mlxk *window)
{
	if (dbt(window->xh, window->yh, window->x0, window->y0)
		> dbt(window->xv, window->yv, window->x0, window->y0))
	{
		*x1 = window->xv;
		*y1 = window->yv;
	}
	else
	{
		*x1 = window->xh;
		*y1 = window->yh;
	}
	window->length = dbt(*x1, *y1, window->x0, window->y0);
}
