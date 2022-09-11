#include "cub3d.h"

int	controlplayer(int key, t_mlxk *params)
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
	if (key == 53)
		exit(0);
	if (key == 2)
	{
		mlx_clear_window(params->mlx, params->mlx_win);
		params->angle += 0.1;
		vision(*params, 0, params->angle);
	}
	else if (key == 13)
	{
		mlx_clear_window(params->mlx, params->mlx_win);
		if (hitwall(map, params->x0 + 5 * cos(params->angle), params->y0 + 5 * sin(params->angle)) == 0)
		{
			params->y0 += 5 * sin(params->angle);
			params->x0 += 5 * cos(params->angle);
		}
		vision(*params, 0, params->angle);
	}
	else if (key == 1)
	{
		mlx_clear_window(params->mlx, params->mlx_win);
		if (hitwall(map, params->x0 - 5 * cos(params->angle), params->y0 - 5 * sin(params->angle)) == 0)
		{
			params->y0 -= 5 * sin(params->angle);
			params->x0 -= 5 * cos(params->angle);
		}
		vision(*params, 0, params->angle);
	}
	else if (key == 0)
	{
		mlx_clear_window(params->mlx, params->mlx_win);
		params->angle -= 0.1;
		vision(*params, 0, params->angle);
	}
	drawmap(map, *params);
	return 0;
}

int	main(void)
{
	t_mlxk	window;
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
	window.x0 = 100;
	window.y0 = 100;
	window.angle = 0;
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1500, 500, "cub3d");
	drawmap(map, window);
	vision(window, 0, window.angle);
	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	mlx_loop(window.mlx);
}