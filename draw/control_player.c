#include "../cub3D.h"

void	camera_left(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle += rotates;
	if (params->angle > pi * 2)
		params->angle = 0;
	vision(params, params->angle, params->map);
}

void	move_forward(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	if (hitwall(params->table, params->x0 + 30 * cos(params->angle), params->y0 + 30 * sin(params->angle)) == 0)
	{
		params->y0 += movements * sin(params->angle);
		params->x0 += movements * cos(params->angle);
	}
	vision(params, params->angle, params->map);
}

void	move_backward(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	if (hitwall(params->table, params->x0 - 30 * cos(params->angle), params->y0 - 30 * sin(params->angle)) == 0)
	{
		params->y0 -= movements * sin(params->angle);
		params->x0 -= movements * cos(params->angle);
	}
	vision(params, params->angle, params->map);
}

void	camera_right(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle -= rotates;
	if (params->angle < 0)
		params->angle = pi * 2;
	vision(params, params->angle, params->map);
}