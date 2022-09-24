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

void	ray_to_3d(t_mlxk *window, double length, int i)
{
	int		lineh;
	double	y;
	double	d;

	d = 0;
	if (i <= (nray / 2) - 1)
		length *= cos(angleV - (((i % (nray / 2)) * degre)));
	else if (i >= (nray / 2))
		length *= cos((i % (nray / 2)) * degre);
	lineh = 50 * window->screenY / length;
	y = (window->screenY + window->up - lineh) / 2;
	window->kb += 1;
	while ((int)y < lineh + (window->screenY + window->up - lineh) / 2)
	{
		if (window->length == dbt(window->xh,
				window->yh, window->x0, window->y0))
			horizantal_pixel(window, d, y);
		else if (window->length == dbt(window->xv,
				window->yv, window->x0, window->y0))
			vertical_pixel(window, d, y);
		d += (32.00000 / lineh);
		y++;
	}
}
