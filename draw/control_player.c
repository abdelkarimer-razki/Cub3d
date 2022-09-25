/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:12:47 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:12:49 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	camera_left(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle += params->rotates;
	if (params->angle > PI * 2)
		params->angle = 0;
	vision(params, params->angle, params->map);
}

void	move_forward(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	if (hitwall(params, params->x0, params->y0, 1) == 0)
	{
		params->y0 += MOVEMENTS * sin(params->angle);
		params->x0 += MOVEMENTS * cos(params->angle);
	}
	vision(params, params->angle, params->map);
}

void	move_backward(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	if (hitwall(params, params->x0, params->y0, 0) == 0)
	{
		params->y0 -= MOVEMENTS * sin(params->angle);
		params->x0 -= MOVEMENTS * cos(params->angle);
	}
	vision(params, params->angle, params->map);
}

void	move_right(t_mlxk *params)
{
	double	x;
	double	y;

	x = params->x0;
	y = params->y0;
	if (params->angle > 5 * PI / 4 && params->angle < 7 * PI / 4)
		x += MOVEMENTS;
	else if (params->angle > PI / 4 && params->angle < 3 * PI / 4)
		x -= MOVEMENTS;
	else if (params->angle > 7 * PI / 4 || params->angle < PI / 4)
		y += MOVEMENTS;
	else if (params->angle > 3 * PI / 4 || params->angle < 5 * PI / 4)
		y -= MOVEMENTS;
	if (hitwall_lite(params, x, y) != 1)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->x0 = x;
		params->y0 = y;
		vision(params, params->angle, params->map);
	}
}

void	camera_right(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle -= params->rotates;
	if (params->angle < 0)
		params->angle = PI * 2;
	vision(params, params->angle, params->map);
}
