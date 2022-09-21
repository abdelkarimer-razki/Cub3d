/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:10 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/19 12:31:41 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"
#include "../a.ppm"
#include "../pixil-frame-0.ppm"
#include "../New Project (1).ppm"

int	hitwall_horizantal(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (i > 0 && table[i - 1][j] == '1'))
		return (1);
	return (0);
}

int	hitwall(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1')
		return (1);
	return (0);
}

int	hitwall_vertical(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (j > 0 && table[i][j - 1] == '1'))
		return (1);
	return (0);
}

void	vertical_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sy;

	x0 = (int)(window->x0 / care) * care;
	if (angle < pi / 2 || angle > 1.5 * pi)
		x0 += care;
	y0 = window->y0 + tan(angle) * (x0 - window->x0);
	sy = tan(angle) * care;
	if (angle < pi && angle > 0 && sy < 0)
		sy *= -1;
	else if (!(angle < pi && angle > 0) && sy > 0)
		sy *= -1;
	while (hitwall_vertical(window->table, x0, y0) == 0)
	{
		if (angle < pi / 2 || angle > 1.5 * pi)
			x0 += care;
		else
			x0 -= care;
		y0 += sy;
	}
	(*x1) = x0;
	(*y1) = y0;
}

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
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

void	horizontal_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sx;

	y0 = (int)(window->y0 / care) * care;
	if (angle < pi && angle > 0)
		y0 += care;
	x0 = window->x0 + ((y0 - window->y0) / tan(angle));
	sx = care / tan(angle);
	if (!(angle < pi / 2 || angle > 1.5 * pi) && sx > 0)
		sx *= -1;
	else if ((angle < pi / 2 || angle > 1.5 * pi) && sx < 0)
		sx *= -1;
	while (hitwall_horizantal(window->table, x0, y0) == 0)
	{
		if (angle < pi && angle > 0)
			y0 += care;
		else
			y0 -= care;
		x0 += sx;
	}
	(*x1) = x0;
	(*y1) = y0;
}

int	rgb_to_int(int opacity, int red, int green, int blue)
{
	return ((opacity * 16777216) + (red * 65536) + (green * 256) + blue);
}

void	ray_to_3d(t_mlxk *window, double length, int i)
{
	int		lineh;
	double	y;
	float	d;

	d = 0;
	if (i <= (nray / 2) - 1)
		length *= cos(angleV - (((i % (nray / 2)) * degre)));
	else if (i >= (nray / 2))
		length *= cos((i % (nray / 2)) * degre);
	lineh = 50 * window->screenY / length;
	y = (window->screenY - lineh) / 2;
	window->kb += 1;
	while ((int)y < lineh + (window->screenY - lineh) / 2)
	{
		if (window->length == dbt(window->xh, window->yh, window->x0, window->y0))
		{
			int red = wall[((((int)d * 32) + ((int)window->xh % 32)) * 3)];
			int green = wall[((((int)d * 32) + ((int)window->xh % 32)) * 3) + 1];
			int blue = wall[((((int)d * 32) + ((int)window->xh % 32)) * 3) + 2];
			my_mlx_pixel_put(window, window->kb, y, rgb_to_int(0 ,red, green, blue));
		}
		else if (window->length == dbt(window->xv, window->yv, window->x0, window->y0))
		{
			int red = textures2[((((int)d * 32) + ((int)window->yv % 32)) * 3)];
			int green = textures2[((((int)d * 32) + ((int)window->yv % 32)) * 3) + 1];
			int blue = textures2[((((int)d * 32) + ((int)window->yv % 32)) * 3) + 2];
			my_mlx_pixel_put(window, window->kb, y, rgb_to_int(0 ,red, green, blue));
		}
		d += (32.00000 / lineh);
		y++;
	}
}
