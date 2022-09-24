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

	i = window->kb  - 1;
	while (++i < window->screenx)
	{
		j = -1;
		while (++j < window->screeny + window->up)
		{
			if (j < (window->screeny + window->up) / 2)
				my_mlx_pixel_put(window, i, j , rgb_to_int(0,
					window->map->f_num[0], window->map->f_num[1], window->map->f_num[2]));
			else
				my_mlx_pixel_put(window, i, j , rgb_to_int(0,
					window->map->c_num[0], window->map->c_num[1], window->map->c_num[2]));
		}
	}		
}

void	playerpositon(t_mlxk *window)
{
	int	i;
	int	y;
	int x;

	i = window->x0 - 1;
	while (++i  < window->x0 + 10)
	{
		y = window->y0 - 1;
		while (++y < window->y0 + 10)
			my_mlx_pixel_put1(window, i, y, rgb_to_int(0, 255, 0, 0));
	}
	i = -1;
	while (++i < 360)
	{
		x = (window->screenx/2) + 15 * cos(i);
		y = (window->screeny/2) + 15 * sin(i);
		my_mlx_pixel_put(window, x, y, 16777215);
	}
}

void    vision(t_mlxk *window, double angle, t_map *map)
{
	int	i;

	angle-=ANGLEV;
	if (angle < 0)
		angle = (PI * 2) + angle;
	window->img = mlx_new_image(window->mlx, window->screenx, window->screeny);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
								&window->endian);
	sky_and_floor(window);
	i = -1;
	while (++i < NRAY)
	{
		dda(window, angle, i);
		angle += DEGRE;
		if (angle > PI * 2)
			angle = DEGRE;
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

int		usemouse(int x, int y, t_mlxk *params)
{
	if (x > 0 && x < params->screenx && y < params->screeny && y > 0)
	{
		if (x <= params->mx)
			camera_right(params);
		else
			camera_left(params);
		params->mx = x;
	}
	return 0;
}

int	controlplayer(int key, t_mlxk *params)
{
	params->kb = 0;
	if (key == 53)
		exit(0);
	if (key == 2)
		camera_left(params);
	else if (key == 13)
		move_forward(params);
	else if (key == 1)
		move_backward(params);
	else if (key == 0)
		camera_right(params);
	else if (key == 126)
		camera_up(params);
	else if (key == 125)
		camera_down(params);
	//person(params);
	return (0);
}


void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < data->screenx) && (y > 0 && y < data->screeny))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}


void	my_mlx_pixel_put1(t_mlxk *data, int x, int y, int color)
{
	char	*dst;
	
	x /= 5;
	y /= 5;
	if ((x > 0 && x < data->screenx) && (y > 0 && y < data->screeny))
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
	if ((x > (data->x0 / 5) - 100 && x < (data->x0 / 5) + 100) && (y > (data->y0 / 5) - 100 && y < (data->y0 / 5) + 100))
	{
		x = x - ((data->x0 / 5) - 130);
		y = y - ((data->y0 / 5) - 130);
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
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
			if (map->table[i][j] == '1' || (i > 0 && map->table[i - 1][j] == '1'))
			{
				c = (j * CARE) - 1;
				while (++c < (j + 1) * CARE)
					my_mlx_pixel_put2(window, c , i * CARE, 16776960);
			}
			if (map->table[i][j] == '1' || (j > 0 && map->table[i][j - 1] == '1'))
			{
				c = (i * CARE) - 1;
				while (++c < (i + 1) * CARE)
					my_mlx_pixel_put2(window, j * CARE, c, 16776960);
			}
		}
			if (map->table[i][j] == '1' || (i > 0 && map->table[i - 1][j] == '1'))
			{
				c = (j * CARE) - 1;
				while (++c < (j + 1) * CARE)
					my_mlx_pixel_put2(window, c , i * CARE, 16776960);
			}
			if (map->table[i][j] == '1' || (j > 0 && map->table[i][j - 1] == '1'))
			{
				c = (i * CARE) - 1;
				while (++c < (i + 1) * CARE)
					my_mlx_pixel_put2(window, j * CARE, c, 16776960);
			}
	}
}
