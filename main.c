/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:29:15 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/12 14:30:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*int	controlplayer(int key, t_mlxk *params)
{
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
		vision(params, 0, params->angle);
	}
	else if (key == 13)
	{
		if (hitwall(map, params->x0 + 5 * cos(params->angle), params->y0 + 5 * sin(params->angle)) == 0)
		{
			params->y0 += 5 * sin(params->angle);
			params->x0 += 5 * cos(params->angle);
		}
		vision(params, 0, params->angle);
	}
	else if (key == 1)
	{
		if (hitwall(map, params->x0 - 5 * cos(params->angle), params->y0 - 5 * sin(params->angle)) == 0)
		{
			params->y0 -= 5 * sin(params->angle);
			params->x0 -= 5 * cos(params->angle);
		}
		vision(params, 0, params->angle);
	}
	else if (key == 0)
	{
		params->angle -= degre;
		vision(params, 0, params->angle);
	}
	return 0;
}

// int	main(void)
// {
// 	t_mlxk	window;

// 	window.x0 = 100;
// 	window.y0 = 100;
// 	karim = 500;
// 	window.rest = 500;
// 	window.angle = 90;
// 	int l = 0;
// 	int colors2[9] = {16777164, 16777113, 16777062, 16777011, 16776960, 13421568, 10066176, 6710784, 3355392};
// 	while (l < 9)
// 	{
// 		colors[l] = colors2[l];
// 		l++;
// 	}
// 	window.mlx = mlx_init();
// 	window.mlx_win = mlx_new_window(window.mlx, 1500, 500, "cub3d");
// 	vision(&window, 0, window.angle);
// 	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
// 	mlx_loop(window.mlx);
// }*/