/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:39:14 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/25 20:03:45 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_values(t_map *map)
{
	map->table = NULL;
	map->cc = 0;
	map->ea = 0;
	map->fc = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->c_info = NULL;
	map->ea_info = NULL;
	map->f_info = NULL;
	map->no_info = NULL;
	map->so_info = NULL;
	map->we_info = NULL;
}

void	free_all(t_map *map)
{
	ft_free(map->table);
	free(map->c_info);
	free(map->ea_info);
	free(map->f_info);
	free(map->no_info);
	free(map->so_info);
	free(map->we_info);
	free(map->texture_ea);
	free(map->texture_no);
	free(map->texture_so);
	free(map->texture_we);
	free(map);
}

void	player_position(char **table, t_mlxk *window)
{
	int	i;
	int	j;

	i = -1;
	while (table[++i])
	{
		j = -1;
		while (table[i][++j])
		{
			if (table[i][j] == 'N' || table[i][j] == 'S'
				|| table[i][j] == 'W' || table[i][j] == 'E')
			{
				window->x0 = j * CARE - (CARE / 2);
				window->y0 = i * CARE - (CARE / 2);
				if (table[i][j] == 'N')
					window->angle = PI * 1.5;
				else if (table[i][j] == 'S')
					window->angle = PI / 2;
				else if (table[i][j] == 'E')
					window->angle = 0;
				else if (table[i][j] == 'W')
					window->angle = PI;
			}
		}
	}
}

void	initialize(t_mlxk *window, t_map *map)
{
	window->kb = 0;
	window->up = 0;
	window->map = map;
	window->degre = (0.0174533 * 60) / SCREENX;
	window->rotates = window->degre * 80;
	window->anglev = (SCREENX * window->degre) / 2;
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, SCREENX,
			SCREENY, "TBC (The best cub3d)");
}

int	main(int ac, char **av)
{
	t_mlxk	window;
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	put_values(map);
	check_exten(av[1], ac);
	parsing(av[1], map);
	player_position(map->table, &window);
	initialize(&window, map);
	window.tl = ft_strlen_2(map->table);
	vision(&window, window.angle);
	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	mlx_hook(window.mlx_win, 17, 0, &ft_exit, NULL);
	mlx_loop(window.mlx);
	free_all(map);
	return (0);
}
