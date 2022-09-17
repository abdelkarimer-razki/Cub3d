#include "cub3d.h"


int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}

int	controlplayer(int key, t_mlxk *params)
{
	int		map[64] = 
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};
	params->kb = 500;
	if (key == (2 | 13 | 1 | 0))
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
	}
	if (key == 53)
		exit(0);
	if (key == 2)
	{
		params->angle += rotates;
		if (params->angle > pi * 2)
			params->angle = 0;
		vision(params, params->angle);
	}
	else if (key == 13)
	{
		if (hitwall(map, params->x0 + movements * cos(params->angle), params->y0 + movements * sin(params->angle)) == 0)
		{
			params->y0 += movements * sin(params->angle);
			params->x0 += movements * cos(params->angle);
		}
		vision(params, params->angle);
	}
	else if (key == 1)
	{
		if (hitwall(map, params->x0 - movements * cos(params->angle), params->y0 - movements * sin(params->angle)) == 0)
		{
			params->y0 -= movements * sin(params->angle);
			params->x0 -= movements * cos(params->angle);
		}
		vision(params, params->angle);
	}
	else if (key == 0)
	{
		params->angle -= rotates;
		if (params->angle < 0)
			params->angle = pi * 2;
		vision(params, params->angle);
	}
	/*if (key == 49)
	{
		params->screenY -= 20;
		vision(params, params->angle);
		sleep(2);
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->screenY += 20;
		vision(params, params->angle);
	}*/
	return 0;
}

int	main(void)
{
	t_mlxk	window;

	window.x0 = 200;
	window.y0 = 200;
	window.kb = 500;
	window.rest = 500;
	window.screenX = 1500;
	window.screenY = 500;
	window.angle = 2*pi;
	int l = 0;
	int colors2[9] = {16777164, 16777113, 16777062, 16777011, 16776960, 13421568, 10066176, 6710784, 3355392};
	while (l < 9)
	{
		colors[l] = colors2[l];
		l++;
	}
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, window.screenX, window.screenY, "cub3d");
	vision(&window, window.angle);
	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	//mlx_hook(window.mlx_win, 6, 0, &usemouse, &window);
	mlx_hook(window.mlx_win, 17, 0, &ft_exit, &window);
	mlx_loop(window.mlx);
}