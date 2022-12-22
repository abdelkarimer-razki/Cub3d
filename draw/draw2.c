/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:10 by bboulhan          #+#    #+#             */
/*   Updated: 2022/12/22 14:52:32 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	vertical_lines(t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sy;
	double	tana;

	tana = tan(angle);
	x0 = (int)(window->x0 / CARE) * CARE;
	if (angle < PI / 2 || angle > 1.5 * PI)
		x0 += CARE;
	y0 = window->y0 + tana * (x0 - window->x0);
	sy = tana * CARE;
	if (angle < PI && angle > 0 && sy < 0)
		sy *= -1;
	else if (!(angle < PI && angle > 0) && sy > 0)
		sy *= -1;
	while (!hitwall_vertical(window->map->table, x0, y0, window->tl))
	{
		if (angle < PI / 2 || angle > 1.5 * PI)
			x0 += CARE;
		else
			x0 -= CARE;
		y0 += sy;
	}
	window->xv = x0;
	window->yv = y0;
}

void	horizontal_lines(t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sx;
	double	tana;

	tana = tan(angle);
	y0 = (int)(window->y0 / CARE) * CARE;
	if (angle < PI && angle > 0)
		y0 += CARE;
	x0 = window->x0 + ((y0 - window->y0) / tana);
	sx = CARE / tana;
	if (!(angle < PI / 2 || angle > 1.5 * PI) && sx > 0)
		sx *= -1;
	else if ((angle < PI / 2 || angle > 1.5 * PI) && sx < 0)
		sx *= -1;
	while (!hitwall_horizantal(window->map->table, x0, y0, window->tl))
	{
		if (angle < PI && angle > 0)
			y0 += CARE;
		else
			y0 -= CARE;
		x0 += sx;
	}
	window->xh = x0;
	window->yh = y0;
}

void	ray_to_3d(t_mlxk *window, double length, int i, double angle)
{
	int		lineh;
	double	y;
	double	d;
	double	pixel_step;
	int		limit;

	d = 0;
	if (i <= (SCREENX / 2) - 1)
		length *= cos(window->anglev - (((i % (SCREENX / 2)) * window->degre)));
	else if (i >= (SCREENX / 2))
		length *= cos((i % (SCREENX / 2)) * window->degre);
	lineh = 50 * SCREENY / length;
	pixel_step = ((double)CARE / lineh);
	limit = lineh + (SCREENY + window->up - lineh) / 2;
	y = (SCREENY + window->up - lineh) / 2;
	if (y < 0)
	{
		d += (pixel_step * y * -1);
		y = 0;
	}
	window->kb += 1;
	while ((int)y < limit)
	{
		if (window->length == dbt(window->xh,
				window->yh, window->x0, window->y0))
			horizantal_pixel(window, d, y, angle);
		else if (window->length == dbt(window->xv,
				window->yv, window->x0, window->y0))
			vertical_pixel(window, d, y, angle);
		d += pixel_step;
		y++;
		if (y > SCREENY)
			break ;
	}
}

void	drawmap(t_mlxk *window)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (window->map->table[++i])
	{
		j = -1;
		while (window->map->table[i][++j])
		{
			c = (j * CARE) - 1;
			if (window->map->table[i][j] == '1'
				|| (i > 0 && window->map->table[i - 1][j] == '1'))
				while (++c < (j + 1) * CARE)
					my_mlx_pixel_put2(window, c, i * CARE, 16776960);
			c = (i * CARE) - 1;
			if (window->map->table[i][j] == '1'
				|| (j > 0 && window->map->table[i][j - 1] == '1'))
				while (++c < (i + 1) * CARE)
					my_mlx_pixel_put2(window, j * CARE, c, 16776960);
		}
	}
}
