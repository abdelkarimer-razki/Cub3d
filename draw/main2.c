/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:38:58 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/17 12:22:59 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

void    vision(t_mlxk *window, double lenght, double angle, t_map *map)
{
	int i;
	angle-=angleV;
	if (angle <= 0)
		angle = (pi * 2) - degre;
	i = -1;
	window->img = mlx_new_image(window->mlx, 1500, 500);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length, &window->endian);
	drawmap(map, window);
	while (++i < nray)
	{
		dda(window, lenght, angle, i);
		angle += degre;
		if (angle >= pi * 2)
			angle = degre;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
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

int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}

int usemouse(int x, int y, t_mlxk *params, t_map *map)
{
	(void) y;
	if (x > 500)
	{
		mlx_destroy_image(params->mlx, params->img);
		//mlx_clear_window(params->mlx, params->mlx_win);
		if (x < 1000 )
		{
			vision(params, 0, params->angle, map);
			params->angle += degre;
		}
		else if (x <= 1500)
		{
			params->angle -= degre;
			vision(params, 0, params->angle, map);
		}
	}
	return 0;
}

int	controlplayer(int key, t_mlxk *params)
{
	karim = 500;
	if (key == (2 | 13 | 1 | 0))
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
	}
	if (key == 53)
		exit(0);
	if (key == 2)
	{
		params->angle += degre;
		if (params->angle >= pi * 2)
			params->angle = degre;
		vision(params, 0, params->angle, params->map);
	}
	else if (key == 13)
	{
		if (hitwall(params->table, params->x0 + movements * cos(params->angle), params->y0 + movements * sin(params->angle)) == 0)
		{
			params->y0 += movements * sin(params->angle);
			params->x0 += movements * cos(params->angle);
		}
		vision(params, 0, params->angle, params->map);
	}
	else if (key == 1)
	{
		if (hitwall(params->table, params->x0 - movements * cos(params->angle), params->y0 - movements * sin(params->angle)) == 0)
		{
			params->y0 -= movements * sin(params->angle);
			params->x0 -= movements * cos(params->angle);
		}
		vision(params, 0, params->angle, params->map);
	}
	else if (key == 0)
	{
		params->angle -= degre;
		if (params->angle <= 0)
			params->angle = (pi * 2) - degre;
		vision(params, 0, params->angle, params->map);
	}
	return 0;
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

void	drawmap(t_map *map, t_mlxk *window)
{
	int	i;
	int	j;
	int	c;
	int	k;

	i = -1;
	while (map->table[++i])
	{
		k = 0;
		j = -1;
		while (map->table[i][++j])
		{
			//printf("%c\t%d\t%d\n", map->table[i][j], i, j);
				printf("1\n");
			if (map->table[i][j] == '1')
			{
				c = k * care;
				while (c < (k + 1) * care)
				{
					my_mlx_pixel_put(window, c, i * care, yellow);
					c++;
				}
				printf("2\n");
				c = i * care;
				while (c < (i + 1) * care)
				{
					my_mlx_pixel_put(window, k * care, c, yellow);
					c++;
				}
				printf("3\n");
			}
			else
			{
				if (j > 0 && map->table[i][j - 1] == '1')
				{
					c = i * care;
					while (c < (i + 1) * care)
					{
						my_mlx_pixel_put(window, k * care, c, yellow);
						c++;
					}
				}
				printf("4\n");
				if (i > 0 && map->table[i - 1][j] == '1')
				{
					printf("5\n");
					c = k * care;
					while (c < (k + 1) * care)
					{
						my_mlx_pixel_put(window, c, i * care, yellow);
						c++;
					}
				}
			}
			k++;
		}
	}
}