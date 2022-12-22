/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:14:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/12/22 14:48:06 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	vertical_pixel(t_mlxk *window, double d, double y, double angle)
{
	int index;
	t_rgb	colors;

	index = ((((int)d * CARE) + ((int)window->yv % CARE)) * 3);
	if (angle < PI / 2 || angle > PI * 1.5)
	{
		colors.red = window->map->texture_ea[index];
		colors.green = window->map->texture_ea[index + 1];
		colors.blue = window->map->texture_ea[index + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, colors.red, colors.green, colors.blue));
	}
	else
	{
		colors.red = window->map->texture_we[index];
		colors.green = window->map->texture_we[index + 1];
		colors.blue = window->map->texture_we[index + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, colors.red, colors.green, colors.blue));
	}
}

void	horizantal_pixel(t_mlxk *window, double d, double y, double angle)
{
	int index;
	t_rgb	colors;

	index = ((((int)d * CARE) + ((int)window->xh % CARE)) * 3);
	if (angle > 0 && angle < PI)
	{
		colors.red = window->map->texture_no[index];
		colors.green = window->map->texture_no[index + 1];
		colors.blue = window->map->texture_no[index + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, colors.red, colors.green, colors.blue));
	}
	else
	{
		colors.red = window->map->texture_so[index];
		colors.green = window->map->texture_so[index + 1];
		colors.blue = window->map->texture_so[index + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, colors.red, colors.green, colors.blue));
	}
}
