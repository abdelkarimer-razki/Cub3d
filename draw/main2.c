/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:38:58 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/25 20:00:59 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	sky_and_floor(t_mlxk *window)
{
	int	i;
	int	j;

	i = window->kb - 1;
	while (++i < SCREENX)
	{
		j = -1;
		while (++j < SCREENY + window->up)
		{
			if (j < (SCREENY + window->up) / 2)
				my_mlx_pixel_put(window, i, j, rgb_to_int(0,
						window->map->f_num[0],
						window->map->f_num[1], window->map->f_num[2]));
			else
				my_mlx_pixel_put(window, i, j, rgb_to_int(0,
						window->map->c_num[0],
						window->map->c_num[1], window->map->c_num[2]));
		}
	}		
}

void	playerpositon(t_mlxk *window)
{
	double	i;
	double	y;

	i = window->x0 - 1;
	while (++i < window->x0 + 10)
	{
		y = window->y0 - 1;
		while (++y < window->y0 + 10)
			my_mlx_pixel_put1(window, i, y, rgb_to_int(0, 255, 0, 0));
	}
}

void	vision(t_mlxk *window, double angle)
{
	int	i;

	angle -= window->anglev;
	if (angle < 0)
		angle = (PI * 2) + angle;
	window->img = mlx_new_image(window->mlx, SCREENX, SCREENY);
	window->addr = mlx_get_data_addr(window->img,
			&window->bits_per_pixel, &window->line_length,
			&window->endian);
	sky_and_floor(window);
	i = -1;
	while (++i < SCREENX)
	{
		dda(window, angle, i);
		angle += window->degre;
		if (angle > PI * 2)
			angle = window->degre;
	}
	drawmap(window);
	playerpositon(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}

void	dda(t_mlxk *window, double angle, int i)
{
	horizontal_lines(window, angle);
	vertical_lines(window, angle);
	shortdistance(window);
	ray_to_3d(window, window->length, i, angle);
}
