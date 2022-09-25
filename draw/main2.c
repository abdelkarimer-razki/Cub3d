/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:38:58 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/22 21:12:07 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	sky_and_floor(t_mlxk *window)
{
	int	i;
	int	j;

	i = window->kb - 1;
	while (++i < window->screenx)
	{
		j = -1;
		while (++j < window->screeny + window->up)
		{
			if (j < (window->screeny + window->up) / 2)
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
	int		x;

	i = window->x0 - 1;
	while (++i < window->x0 + 10)
	{
		y = window->y0 - 1;
		while (++y < window->y0 + 10)
			my_mlx_pixel_put1(window, i, y, rgb_to_int(0, 255, 0, 0));
	}
	i = -1;
	while (++i < 360)
	{
		x = (window->screenx / 2) + 15 * cos(i);
		y = (window->screeny / 2) + 15 * sin(i);
		my_mlx_pixel_put(window, x, y, 16777215);
	}
}

void	vision(t_mlxk *window, double angle, t_map *map)
{
	int	i;

	angle -= window->anglev;
	if (angle < 0)
		angle = (PI * 2) + angle;
	window->img = mlx_new_image(window->mlx, window->screenx, window->screeny);
	window->addr = mlx_get_data_addr(window->img,
			&window->bits_per_pixel, &window->line_length,
			&window->endian);
	sky_and_floor(window);
	i = -1;
	while (++i < NRAY)
	{
		dda(window, angle, i);
		angle += window->degre;
		if (angle > PI * 2)
			angle = window->degre;
	}
	drawmap(map, window);
	playerpositon(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}

void	dda(t_mlxk *window, double angle, int i)
{
	double	x1;
	double	y1;
	double	x0;
	double	y0;

	x0 = window->x0;
	y0 = window->y0;
	horizontal_lines(&window->xh, &window->yh, window, angle);
	vertical_lines(&window->xv, &window->yv, window, angle);
	shortdistance(&x1, &y1, window);
	ray_to_3d(window, dbt(x1, y1, x0, y0), i, angle);
}

int	usemouse(int x, int y, t_mlxk *params)
{
	my_mlx_pixel_put(params, x, y, 16777215);
	if (x > 0 && x < params->screenx && y < params->screeny && y > 0)
	{
		if (x <= params->screenx / 2)
			camera_left(params);
		else
			camera_right(params);
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		vision(params, params->angle, params->map);
	}
	return (0);
}
