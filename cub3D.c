/* ****** ******************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:22:08 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/07 13:30:06 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	print(t_map *map)
{
	int i = -1;
	printf("%s\n", map->C_info);
	printf("%s\n", map->F_info);
	printf("%s\n", map->NO_info);
	printf("%s\n", map->SO_info);
	printf("%s\n", map->WE_info);
	printf("%s\n", map->EA_info);
	printf("--------------\n");
	while (map->table[++i])
		printf("%s\n", map->table[i]);
}




void	put_values(t_map *map)
{
	map->table = NULL;
    map->C = 0;
    map->EA = 0;
	map->F = 0;
	map->NO = 0;
	map->SO = 0;
	map->WE = 0;
	map->C_info = NULL;
	map->EA_info = NULL;
	map->F_info = NULL;
	map->NO_info = NULL;
	map->SO_info = NULL;
	map->WE_info = NULL;
}

int	main(int ac, char **av)
{
	//t_mlxk	window;
	t_map *map;

	map = malloc(sizeof(t_map) * 1);
	put_values(map);
    check_exten(av[1], ac);
	parsing(av[1], map);
	print(map);
	// window.x0 = 100;
	// window.y0 = 100;
	// window.angle = 0;
	// window.mlx = mlx_init();
	// window.mlx_win = mlx_new_window(window.mlx, 1500, 500, "cub3d");
	// drawmap(window, map);
	// vision(window, 0, window.angle);
	// mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	// mlx_loop(window.mlx);
    return 0; 
}