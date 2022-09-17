/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:04 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/23 15:47:06 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <math.h>
#include <stdio.h>
# include "pixil-frame-0.ppm"

void	vertical_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sy;
	int		map[64] = 
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};

	x0 = (int)(window->x0/ 62) * 62;
	if (angle < pi / 2 || angle > 1.5 * pi)
		x0 += 62;
	y0 = window->y0 + tan(angle) * (x0 - window->x0);
	sy = tan(angle) * 62;
	if (angle < pi && angle > 0 && sy < 0)
		sy *= -1;
	else if (!(angle < pi && angle > 0) && sy > 0)
		sy *= -1;
	while (hitwall_vertical(map, x0, y0) == 0)
	{
		if (angle < pi / 2 || angle > 1.5 * pi)
			x0 += 62;
		else
			x0 -= 62;
		y0 += sy;
	}
	(*x1) = x0;
	(*y1) = y0;
}

void	horizontal_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double x0;
	double y0;
	int		map[64] = 
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};

	y0 = (int)(window->y0/ 62) * 62;
	if (angle < pi && angle > 0)
		y0 += 62;
	x0 = window->x0 + ((y0 - window->y0) / tan(angle));
	float sx = 62 / tan(angle);
	if (!(angle < pi / 2 || angle > 1.5 * pi) && sx > 0)
		sx *= -1;
	else if ((angle < pi / 2 || angle > 1.5 * pi) && sx < 0)
		sx *= -1;
	while (hitwall_horizantal(map, x0, y0) == 0)
	{
		if (angle < pi && angle > 0)
			y0 += 62;
		else
			y0 -= 62;
		x0 += sx;
	}
	(*x1) = x0;
	(*y1) = y0;
}

int	rgb_to_int(int red, int green, int blue)
{
	return ((red * 65536) + (green * 256) + blue);
}

void	ray_to_3d(t_mlxk *window, double length, int i)
{
	int lineH;
	double	y;
	double x;
	int lineA;

	if (i <= (nray / 2) - 1)
		length *= cos(angleV - (((i % (nray / 2)) * degre)));
	else if(i >= (nray / 2))
		length *= cos((i % (nray / 2)) * degre);
	lineH = 50 * 500 / length;
	if (lineH > window->screenY)
		lineH = window->screenY;
	y = (window->screenY - lineH) / 2;
	lineA = 1000 / nray;
	while ((int)y < lineH + (window->screenY - lineH) / 2)
	{
		x = window->kb;
		while ((int)x < lineA + window->kb)
		{
			if (window->length == dbt(window->xh, window->yh, window->x0, window->y0))
				my_mlx_pixel_put(window, x, y, colors[3]);
			else if (window->length == dbt(window->xv, window->yv, window->x0, window->y0))
				my_mlx_pixel_put(window, x, y, colors[5]);
			x++;
		}
		y++;
	}
	window->kb += lineA;
}

void vision(t_mlxk *window, double angle)
{
	int i;
	angle-=angleV;
	if (angle < 0)
		angle = (pi * 2) + angle;
	i = -1;
	int		map[64] = 
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};
	window->img = mlx_new_image(window->mlx, 1500, 500);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
								&window->endian);
	drawmap(map, window);
	while (++i < nray)
	{
		dda(window, angle, i);
		angle += degre;
		if (angle > pi * 2)
			angle = degre;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}

void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < 1500) && (y > 0 && y < 500))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	hitwall(int *map, int x1, int y1)
{
	if (x1 > 500 || x1 < 0 || y1 > 500 | y1 < 0)
		return (1);
	if (map[(x1 / 62 + (8 * (y1 / 62)))] == 1)
		return (1);
	return (0); 
}

int	hitwall_horizantal(int *map, int x1, int y1)
{
	if (x1 > 500 || x1 < 0 || y1 > 500 | y1 < 0)
		return (1);
	if (map[(x1 / 62 + (8 * (y1 / 62)))] == 1 || (map[(x1 / 62 + (8 * ((y1 / 62) - 1)))] == 1))
		return (1);
	return (0); 
}

int	hitwall_vertical(int *map, int x1, int y1)
{
	if (x1 > 500 || x1 < 0 || y1 > 500 | y1 < 0)
		return (1);
	if (map[(x1 / 62 + (8 * (y1 / 62)))] == 1 || map[(x1 / 62 - 1 + (8 * (y1 / 62)))] == 1)
		return (1);
	return (0); 
}

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}

void	shortdistance(double *x1, double *y1, t_mlxk *window)
{
	if (dbt(window->xh, window->yh, window->x0, window->y0) > dbt(window->xv, window->yv, window->x0, window->y0))
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

void	dda(t_mlxk *window, double angle, int i)
{
	double	x1;
	double	y1;
	double	x0;
	double	y0;

	x0 = window->x0;
	y0 = window->y0;
	horizontal_lines(&window->xh, &window->yh, window, angle);
	vertical_lines(&window->xv, &window->yv, window, angle);
	shortdistance(&x1, &y1, window);
	ray_to_3d(window, dbt(x1, y1, x0, y0), i);
	if (fabs(x1 - x0) > fabs(y1 - y0))
	{
		while ((int)x0 != (int)x1)
		{
			my_mlx_pixel_put(window, x0, y0, white);
			y0 += (y1 - y0) / fabs(x1 - x0);
			x0 += (x1 - x0) / fabs(x1 - x0);
		}
	}
	else
	{
		while ((int)y0 != (int)y1)
		{
			my_mlx_pixel_put(window, x0, y0, white);
			y0 += (y1 - y0) / fabs(y1 - y0);
			x0 += (x1 - x0) / fabs(y1 - y0);
		}
	}
}

void	drawmap(int *map, t_mlxk *window)
{
	int	i;
	int	c = -1;
	int j = 0;
	int	k;
	i = 0;
	while (j < 8)
	{
		k = 0;
		while (i < 8 * (j + 1))
		{
			if (map[i] == 1)
			{
				c = k * 62;
				while (c < (k + 1) * 62)
				{
					my_mlx_pixel_put(window, c, j * 62, yellow);
					c++;
				}
				c = j * 62;
				while (c < (j + 1) * 62)
				{
					my_mlx_pixel_put(window, k * 62, c, yellow);
					c++;
				}
			}
			else
			{
				if (map[i - 1] == 1)
				{
					c = j * 62;
					while (c < (j + 1) * 62)
					{
						my_mlx_pixel_put(window, k * 62, c, yellow);
						c++;
					}
				}
				if (map[i - 8] == 1)
				{
					c = k * 62;
					while (c < (k + 1) * 62)
					{
						my_mlx_pixel_put(window, c, j * 62, yellow);
						c++;
					}
				}
			}
			i++;
			k++;
		}
		j++;
	}
}