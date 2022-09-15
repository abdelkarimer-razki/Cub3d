#include "cub3d.h"


int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}

int usemouse(int x, int y, t_mlxk *params)
{
	(void) y;
	if (x > 500)
	{
		mlx_destroy_image(params->mlx, params->img);
		//mlx_clear_window(params->mlx, params->mlx_win);
		if (x < 1000 )
		{
			vision(params, 0, params->angle);
			params->angle += degre;
		}
		else if (x <= 1500)
		{
			params->angle -= degre;
			vision(params, 0, params->angle);
		}
	}
	return 0;
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
		vision(params, 0, params->angle);
	}
	else if (key == 13)
	{
		if (hitwall(map, params->x0 + movements * cos(params->angle), params->y0 + movements * sin(params->angle)) == 0)
		{
			params->y0 += movements * sin(params->angle);
			params->x0 += movements * cos(params->angle);
		}
		vision(params, 0, params->angle);
	}
	else if (key == 1)
	{
		if (hitwall(map, params->x0 - movements * cos(params->angle), params->y0 - movements * sin(params->angle)) == 0)
		{
			params->y0 -= movements * sin(params->angle);
			params->x0 -= movements * cos(params->angle);
		}
		vision(params, 0, params->angle);
	}
	else if (key == 0)
	{
		params->angle -= degre;
		if (params->angle <= 0)
			params->angle = (pi * 2) - degre;
		vision(params, 0, params->angle);
	}
	return 0;
}

int	main(void)
{
	t_mlxk	window;

	window.x0 = 200;
	window.y0 = 200;
	karim = 500;
	window.rest = 500;
	window.angle = 2*pi;
	int l = 0;
	int colors2[9] = {16777164, 16777113, 16777062, 16777011, 16776960, 13421568, 10066176, 6710784, 3355392};
	while (l < 9)
	{
		colors[l] = colors2[l];
		l++;
	}
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1500, 500, "cub3d");
	vision(&window, 0, window.angle);
	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	//mlx_hook(window.mlx_win, 6, 0, &usemouse, &window);
	mlx_hook(window.mlx_win, 17, 0, &ft_exit, &window);
	mlx_loop(window.mlx);
}