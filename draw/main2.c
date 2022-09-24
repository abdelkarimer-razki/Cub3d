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
	while (++i < window->screenX)
	{
		j = -1;
		while (++j < window->screenY + window->up)
		{
			if (j < (window->screenY + window->up) / 2)
				my_mlx_pixel_put(window, i, j , rgb_to_int(0, 56, 56, 56));
			else
				my_mlx_pixel_put(window, i, j , rgb_to_int(0, 113, 113, 113));
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
		x = (window->screenX/2) + 15 * cos(i);
		y = (window->screenY/2) + 15 * sin(i);
		my_mlx_pixel_put(window, x, y, white);
	}
}

void    vision(t_mlxk *window, double angle, t_map *map)
{
	int	i;

	angle-=angleV;
	if (angle < 0)
		angle = (pi * 2) + angle;
	window->img = mlx_new_image(window->mlx, window->screenX, window->screenY);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
								&window->endian);
	sky_and_floor(window);
	i = -1;
	while (++i < nray)
	{
		dda(window, angle, i);
		angle += degre;
		if (angle > pi * 2)
			angle = degre;
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
	ray_to_3d(window, dbt(x1, y1, x0, y0), i);
}

int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}

int		usemouse(int x, int y, t_mlxk *params)
{
		printf("angle:%d\n", params->mx);
	if (x > 0 && x < params->screenX && y < params->screenY && y > 0)
	{
		if (x <= params->mx)
			camera_left(params);
		else
			camera_right(params);
		params->mx = x;

		//person(params);
		//printf("new mx:%d | new angle:%f \n",params->mx, params->angle);
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
	person(params);
	return (0);
}


void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < data->screenX) && (y > 0 && y < data->screenY))
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
	if ((x > 0 && x < data->screenX) && (y > 0 && y < data->screenY))
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
				c = (j * care) - 1;
				while (++c < (j + 1) * care)
					my_mlx_pixel_put2(window, c , i * care, yellow);
			}
			if (map->table[i][j] == '1' || (j > 0 && map->table[i][j - 1] == '1'))
			{
				c = (i * care) - 1;
				while (++c < (i + 1) * care)
					my_mlx_pixel_put2(window, j * care, c, yellow);
			}
		}
			if (map->table[i][j] == '1' || (i > 0 && map->table[i - 1][j] == '1'))
			{
				c = (j * care) - 1;
				while (++c < (j + 1) * care)
					my_mlx_pixel_put2(window, c , i * care, yellow);
			}
			if (map->table[i][j] == '1' || (j > 0 && map->table[i][j - 1] == '1'))
			{
				c = (i * care) - 1;
				while (++c < (i + 1) * care)
					my_mlx_pixel_put2(window, j * care, c, yellow);
			}
	}
}
