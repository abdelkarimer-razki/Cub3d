#include "../cub3D.h"

void	camera_up(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->up += 30 * 2;
	if (params->screeny + params->up > 1700)
		params->up -= 30 * 2;
	vision(params, params->angle, params->map);
}

void	camera_down(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->up -= 30 * 2;
	if (params->screeny + params->up < 1080)
		params->up += 30 * 2;
	vision(params, params->angle, params->map);
}