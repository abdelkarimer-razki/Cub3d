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

#include "cub3d.h"

void print_table(char **table)
{
	int i = 0;
	while (table[i])
		i++;
	//printf("size of i %i\n");
		// printf("%s&\n", table[i]);	
}

void	print(t_map *map)
{
	int i = -1;
	printf("%s\n", map->C_info);
	printf("%s\n", map->F_info);
	printf("%s\n", map->NO_info);
	printf("%s\n", map->SO_info);
	printf("%s\n", map->WE_info);
	printf("%s\n", map->EA_info);
	printf("%d\t%d\n", map->C_num, map->F_num);
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


void	free_all(t_map *map) 
{
	ft_free(map->table);
	free(map->C_info);
	free(map->EA_info);
	free(map->F_info);
	free(map->NO_info);
	free(map->SO_info);
	free(map->WE_info);
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
			if (table[i][j] == 'N' || table[i][j] == 'S' || table[i][j] == 'W' || table[i][j] == 'E')
			{
				window->x0 = j * care - (care / 2);
				window->y0 = i * care - (care / 2);
				break ;
			}
		}
	}
}


int	main(int ac, char **av)
{
	t_mlxk	window;
	t_map *map;

	
	window.kb = 0;
	window.rest = 500;
	window.screenX = 1920;
	window.screenY = 1080;
	window.angle = 0;
	int l = 0;
	int colors2[9] = {16777164, 16777113, 16777062, 16777011, 16776960, 13421568, 10066176, 6710784, 3355392};
	while (l < 9)
	{
		colors[l] = colors2[l];
		l++;
	}

	//-----------parsing----------//
	map = malloc(sizeof(t_map) * 1);
	put_values(map);
    check_exten(av[1], ac);
	parsing(av[1], map);
	//print_table(map->table);
	//----------------------------//

	

	//---------------draw---------------//
	
	window.table = map->table;
	window.map = map;
	player_position(map->table, &window);

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, window.screenX, window.screenY, "TBC (The best cub3d)");
 	vision(&window, window.angle, map);
	//drawmap(map, &window);
	mlx_hook(window.mlx_win, 2, 0, &controlplayer, &window);
	//mlx_hook(window.mlx_win, 6, 0, &usemouse, &window);
	mlx_hook(window.mlx_win, 17, 0, &ft_exit, &window);
	mlx_loop(window.mlx);
	return 0;
}