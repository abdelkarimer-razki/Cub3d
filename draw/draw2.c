/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:10 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/22 15:25:38 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	vertical_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sy;

	x0 = (int)(window->x0 / CARE) * CARE;
	if (angle < PI / 2 || angle > 1.5 * PI)
		x0 += CARE;
	y0 = window->y0 + tan(angle) * (x0 - window->x0);
	sy = tan(angle) * CARE;
	if (angle < PI && angle > 0 && sy < 0)
		sy *= -1;
	else if (!(angle < PI && angle > 0) && sy > 0)
		sy *= -1;
	while (hitwall_vertical(window->table, x0, y0) == 0)
	{
		if (angle < PI / 2 || angle > 1.5 * PI)
			x0 += CARE;
		else
			x0 -= CARE;
		y0 += sy;
	}
	(*x1) = x0;
	(*y1) = y0;
}

void	horizontal_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sx;

	y0 = (int)(window->y0 / CARE) * CARE;
	if (angle < PI && angle > 0)
		y0 += CARE;
	x0 = window->x0 + ((y0 - window->y0) / tan(angle));
	sx = CARE / tan(angle);
	if (!(angle < PI / 2 || angle > 1.5 * PI) && sx > 0)
		sx *= -1;
	else if ((angle < PI / 2 || angle > 1.5 * PI) && sx < 0)
		sx *= -1;
	while (hitwall_horizantal(window->table, x0, y0) == 0)
	{
		if (angle < PI && angle > 0)
			y0 += CARE;
		else
			y0 -= CARE;
		x0 += sx;
	}
	(*x1) = x0;
	(*y1) = y0;
}

void	ray_to_3d(t_mlxk *window, double length, int i, double angle)
{
	int		lineh;
	double	y;
	double	d;

	d = 0;
	if (i <= (NRAY / 2) - 1)
		length *= cos(window->anglev - (((i % (NRAY / 2)) * window->degre)));
	else if (i >= (NRAY / 2))
		length *= cos((i % (NRAY / 2)) * window->degre);
	lineh = 50 * window->screeny / length;
	y = (window->screeny + window->up - lineh) / 2;
	window->kb += 1;
	while ((int)y < lineh + (window->screeny + window->up - lineh) / 2)
	{
		if (window->length == dbt(window->xh,
				window->yh, window->x0, window->y0))
			horizantal_pixel(window, d, y, angle);
		else if (window->length == dbt(window->xv,
				window->yv, window->x0, window->y0))
			vertical_pixel(window, d, y, angle);
		d += ((double)CARE / lineh);
		y++;
	}
}

void	drawmap(t_map *map, t_mlxk *window)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (map->table[++i])
	{
		j = -1;
		while (map->table[i][++j])
		{
			c = (j * CARE) - 1;
			if (map->table[i][j] == '1'
				|| (i > 0 && map->table[i - 1][j] == '1'))
				while (++c < (j + 1) * CARE)
					my_mlx_pixel_put2(window, c, i * CARE, 16776960);
			c = (i * CARE) - 1;
			if (map->table[i][j] == '1'
				|| (j > 0 && map->table[i][j - 1] == '1'))
				while (++c < (i + 1) * CARE)
					my_mlx_pixel_put2(window, j * CARE, c, 16776960);
		}
	}
}
