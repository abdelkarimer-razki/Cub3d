#include "../cub3D.h"

void	camera_left(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle += ROTATES;
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

void	camera_right(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->angle -= ROTATES;
	if (params->angle < 0)
		params->angle = PI * 2;
	vision(params, params->angle, params->map);
}