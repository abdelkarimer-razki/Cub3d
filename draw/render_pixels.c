/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:14:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:14:29 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	vertical_pixel(t_mlxk *window, double d, double y, double angle)
{
	if (angle < PI / 2 || angle > PI * 1.5)
	{
		window->red = window->map->texture_ea
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3)];
		window->green = window->map->texture_ea
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3) + 1];
		window->blue = window->map->texture_ea
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3) + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, window->red, window->green, window->blue));
	}
	else
	{
		window->red = window->map->texture_we
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3)];
		window->green = window->map->texture_we
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3) + 1];
		window->blue = window->map->texture_we
		[((((int)d * CARE) + ((int)window->yv % CARE)) * 3) + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, window->red, window->green, window->blue));
	}
}

void	horizantal_pixel(t_mlxk *window, double d, double y, double angle)
{
	if (angle > 0 && angle < PI)
	{
		window->red = window->map->texture_no
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3)];
		window->green = window->map->texture_no
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3) + 1];
		window->blue = window->map->texture_no
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3) + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, window->red, window->green, window->blue));
	}
	else
	{
		window->red = window->map->texture_so
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3)];
		window->green = window->map->texture_so
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3) + 1];
		window->blue = window->map->texture_so
		[((((int)d * CARE) + ((int)window->xh % CARE)) * 3) + 2];
		my_mlx_pixel_put(window, window->kb, y,
			rgb_to_int(0, window->red, window->green, window->blue));
	}
}
