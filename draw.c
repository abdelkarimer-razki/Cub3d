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
	if ((angle < pi / 2 || angle > 1.5 * pi) && sx < 0)
		sx *= -1;
	while (hitwall(map, x0, y0) == 0)
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
	if ((angle < pi / 2 || angle > 1.5 * pi) && sx < 0)
		sx *= -1;
	while (hitwall(map, x0, y0) == 0)
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

void	ray_to_3d(t_mlxk *window, double length, int i, double x1, double y1)
{
	int lineH;
	double	y;
	double x;
	int lineA;

	int	d;
	int e;
	d = 0;
	while (d < 32)
	{
		e = 0;
		while (e < 32)
		{
			int pixel = (d * 32 + e) * 3;
			int red = textures[pixel + 0];
			int green = textures[pixel + 1];
			int blue = textures[pixel + 2];
			my_mlx_pixel_put(window, e, d, rgb_to_int(red, green, blue));
			e++;
		}
		d++;
	}
	//printf("x1 : %f | y1 : %f | length : %f\n", x1, y1, length);
	if (i <= (nray / 2) - 1)
		length *= cos(angleV - (((i % (nray / 2)) * degre)));
	else if(i >= (nray / 2))
		length *= cos((i % (nray / 2)) * degre);
		//(void) i;
	lineH = 50 * 500 / length;
	if (lineH > 500)
		lineH = 500;
	y = (500 - lineH) / 2;
	x = 0;
	lineA = 1000 / nray;
	while ((int)y < lineH + (500 - lineH) / 2)
	{
		x = karim;
		while ((int)x < lineA + karim)
		{
			/*if ((i > 0 && (int)window->x9 == (int)x1 && (int)window->y9 != (int)y1 && (int)(x1 + 0.01) % 62 == 0 && (int)window->y9 != (int)y1))
				my_mlx_pixel_put(window, x, y, colors[3]);
			else if (i > 0 && (int)window->y9 == (int)y1 && (int)(y1 + 0.01) % 62 == 0)
				my_mlx_pixel_put(window, x, y, colors[6]);*/
			/*if (((int)(x1 + 0.01) % 62 == 0) && ((int)(y1 + 0.01) % 62 == 0))
			{
				if ((x1 - (int)x1) < 0.1)
					my_mlx_pixel_put(window, x, y, colors[6]);
				else
					my_mlx_pixel_put(window, x, y, colors[3]);
			}
			else if ((int)(x1 + 0.01) % 62 == 0)
				my_mlx_pixel_put(window, x, y, colors[3]);
			else
				my_mlx_pixel_put(window, x, y, colors[6]);*/
			/*if (lineH <= 500 && lineH >= 445)
				my_mlx_pixel_put(window, x, y, colors[0]);
			if (lineH <= 444 && lineH >= 389)
				my_mlx_pixel_put(window, x, y, colors[1]);
			if (lineH <= 388 && lineH >= 333)
				my_mlx_pixel_put(window, x, y, colors[2]);
			if (lineH <= 332 && lineH >= 277)
				my_mlx_pixel_put(window, x, y, colors[3]);
			if (lineH <= 276 && lineH >= 221)
				my_mlx_pixel_put(window, x, y, colors[4]);
			if (lineH <= 220 && lineH >= 165)
				my_mlx_pixel_put(window, x, y, colors[5]);
			if (lineH <= 164 && lineH >= 109)
				my_mlx_pixel_put(window, x, y, colors[6]);
			if (lineH <= 108 && lineH >= 53)
				my_mlx_pixel_put(window, x, y, colors[7]);
			if (lineH <= 52)
				my_mlx_pixel_put(window, x, y, colors[8]);*/
			//my_mlx_pixel_put(window, x, y,);	
			x++;
		}
		y++;
	}
	window->x9 = x1;
	window->y9 = y1;
	karim += lineA;
}

void vision(t_mlxk *window, double length, double angle)
{
	int i;
	angle-=angleV;
	if (angle <= 0)
		angle = (pi * 2) - degre;
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
		dda(window, length, angle, i);
		angle += degre;
		if (angle >= pi * 2)
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
	if (map[(x1 / 62 + (8 * (y1 / 62)))] == 1 || (map[(x1 / 62 + (8 * ((y1 / 62) - 1)))] == 1))
		return (1);
	return (0); 
}

void	dda(t_mlxk *window, double length, double angle, int i)
{
	double	x1;
	double	y1;
	double	x0;
	double	y0;

	x0 = window->x0;
	y0 = window->y0;
	x1 = 0;
	y1 = 0;
	(void) i;
	(void) length;
	horizontal_lines(&x1, &y1, window, angle);
	//ray_to_3d(window, length, i, x1, y1);
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