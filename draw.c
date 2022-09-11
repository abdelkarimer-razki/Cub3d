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

void vision(t_mlxk window, int length, double angle)
{
	int i;
	angle = angle - 1;
	i = -1;
	while (++i < 20)
	{
		dda(window, length, angle);
		angle += 0.1;
	}
}

int	hitwall(int *map, int x1, int y1)
{
	if (map[(x1 / 62 + (8 * (y1 / 62)))] == 1)
		return (1);
	return (0);
}

void	dda(t_mlxk window, int length, double angle)
{
	double	x1;
	double	y1;
	double	x0;
	double	y0;
	int		map[64] = 
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 1, 0, 1, 1,
		1, 0, 1, 0, 1, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};

	x0 = window.x0;
	y0 = window.y0;
	x1 = window.x0 + length * cos(angle);
	y1 = window.y0 +length * sin(angle);
	while (hitwall(map, (int)x1, (int)y1) == 0)
	{
		length++;
		x1 = window.x0 + length * cos(angle);
		y1 = window.y0 +length * sin(angle);
	}
	if (abs((int)x1 - (int)x0) > abs((int)y1 - (int)y0))
	{
		while ((int)x0 != (int)x1)
		{
			mlx_pixel_put(window.mlx, window.mlx_win, x0, y0, white);
			y0 += (y1 - y0) / fabs(x1 - x0);
			x0 += (x1 - x0) / fabs(x1 - x0);
		}
	}
	else
	{
		while ((int)y0 != (int)y1)
		{
			mlx_pixel_put(window.mlx, window.mlx_win, (int)x0, (int)y0, white);
			y0 += (y1 - y0) / fabs(y1 - y0);
			x0 += (x1 - x0) / fabs(y1 - y0);
		}
	}
}

void	drawmap(int *map, t_mlxk window)
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
					mlx_pixel_put(window.mlx, window.mlx_win, c, j * 62, yellow);
					c++;
				}
				c = j * 62;
				while (c < (j + 1) * 62)
				{
					mlx_pixel_put(window.mlx, window.mlx_win, k * 62, c, yellow);
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
						mlx_pixel_put(window.mlx, window.mlx_win, k * 62, c, yellow);
						c++;
					}
				}
				if (map[i - 8] == 1)
				{
					c = k * 62;
					while (c < (k + 1) * 62)
					{
						mlx_pixel_put(window.mlx, window.mlx_win, c, j * 62, yellow);
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