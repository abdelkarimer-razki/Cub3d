/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:04 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/11 21:35:53 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	hitwall(t_map *map, int x1, int y1)
{
	if (map->table[y1 / care][x1 / care] == '1')
		return (1);
	// if (map[(x1 / care + (8 * (y1 / care)))] == 1)
	// 	return (1);
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

void drawmap(t_mlxk window, t_map *map)
{
	int	i;
	int	j;
	int	k;
	int	c;

	c = 0;
	k = 0;
	i = 0;
	j = 0;

	while (map->table[i])
	{
		k = 0;
		while (map->table[i][j])
		{
			if (map->table[i][j] == ' ')
			{
			}
			else if (map->table[i][j] == '1')
			{
				c = k * care ;
					while (c < (k + 1) * care)
					{
						mlx_pixel_put(window.mlx, window.mlx_win, c, j * care, yellow);
						c++;
					}
					c = j * care;
					while (c < (j + 1) * care)
					{
						mlx_pixel_put(window.mlx, window.mlx_win, k * care, c, yellow);
						c++;
					}
			}
			else
			{
				if (map->table[i][j - 1] == '1')
					{
						c = j * care;
						while (c < (j + 1) * care)
						{
							mlx_pixel_put(window.mlx, window.mlx_win, k * care, c, yellow);
							c++;
						}
					}
					if (map->table[i - 1][j] == '1')
					{
						c = k * care;
						while (c < (k + 1) * care)
						{
							mlx_pixel_put(window.mlx, window.mlx_win, c, j * care, yellow);
							c++;
						}
					}
			}
			j++;
			k++;
		}
		i++;
	}
}







//---------------------------------------------------------------------------------------------------------------------------//




// void	drawmap(int *map, t_mlxk window, t_map *map2)
// {
// 	int	i;
// 	int	c = -1;
// 	int j = 0;
// 	int	k;
// 	i = 0;
	
// 	while (j < 8)
// 	{
// 		k = 0;
// 		while (i < 8 * (j + 1))
// 		{
// 			if (map[i] == 1)
// 			{
// 				c = k * care;
// 				while (c < (k + 1) * care)
// 				{
// 					mlx_pixel_put(window.mlx, window.mlx_win, c, j * care, yellow);
// 					c++;
// 				}
// 				c = j * care;
// 				while (c < (j + 1) * care)
// 				{
// 					mlx_pixel_put(window.mlx, window.mlx_win, k * care, c, yellow);
// 					c++;
// 				}
// 			}
// 			else
// 			{
// 				if (map[i - 1] == 1)
// 				{
// 					c = j * care;
// 					while (c < (j + 1) * care)
// 					{
// 						mlx_pixel_put(window.mlx, window.mlx_win, k * care, c, yellow);
// 						c++;
// 					}
// 				}
// 				if (map[i - 8] == 1)
// 				{
// 					c = k * care;
// 					while (c < (k + 1) * care)
// 					{
// 						mlx_pixel_put(window.mlx, window.mlx_win, c, j * care, yellow);
// 						c++;
// 					}
// 				}
// 			}
// 			i++;
// 			k++;
// 		}
// 		j++;
// 	}
// }