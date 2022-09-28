/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:12:54 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:12:55 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	camera_up(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	params->up += 30 * 2;
	if (SCREENY + params->up > SCREENY + 500)
		params->up -= 30 * 2;
	vision(params, params->angle);
}

void	camera_down(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	params->up -= 30 * 2;
	if (SCREENY + params->up < SCREENY)
		params->up += 30 * 2;
	vision(params, params->angle);
}

void	move_left(t_mlxk *params)
{
	double	x;
	double	y;

	x = params->x0;
	y = params->y0;
	if (params->angle > 5 * PI / 4 && params->angle < 7 * PI / 4)
		x -= MOVEMENTS;
	else if (params->angle > PI / 4 && params->angle < 3 * PI / 4)
		x += MOVEMENTS;
	else if (params->angle > 7 * PI / 4 || params->angle < PI / 4)
		y -= MOVEMENTS;
	else if (params->angle > 3 * PI / 4 || params->angle < 5 * PI / 4)
		y += MOVEMENTS;
	if (hitwall_lite(params, x, y) != 1)
	{
		mlx_destroy_image(params->mlx, params->img);
		params->x0 = x;
		params->y0 = y;
		vision(params, params->angle);
	}
}

int	controlplayer(int key, t_mlxk *params)
{
	params->kb = 0;
	if (key == 53)
		exit(0);
	if (key == 2)
		move_right(params);
	if (key == 0)
		move_left(params);
	if (key == 124)
		camera_left(params);
	else if (key == 13)
		move_forward(params);
	else if (key == 1)
		move_backward(params);
	else if (key == 123)
		camera_right(params);
	else if (key == 126)
		camera_up(params);
	else if (key == 125)
		camera_down(params);
	return (0);
}
