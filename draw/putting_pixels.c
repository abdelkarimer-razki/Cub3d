/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putting_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:21:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:21:28 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put1(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	x /= 5;
	y /= 5;
	if ((x > 0 && x < SCREENX) && (y > 0 && y < SCREENY))
	{
		x = x - ((data->x0 / 5) - 130);
		y = y - ((data->y0 / 5) - 130);
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put2(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	x /= 5;
	y /= 5;
	if ((x > (data->x0 / 5) - 100 && x < (data->x0 / 5) + 100)
		&& (y > (data->y0 / 5) - 100 && y < (data->y0 / 5) + 100))
	{
		x = x - ((data->x0 / 5) - 130);
		y = y - ((data->y0 / 5) - 130);
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < SCREENX) && (y > 0 && y < SCREENY))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
