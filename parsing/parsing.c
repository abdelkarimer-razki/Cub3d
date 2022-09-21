/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:35:06 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/18 18:00:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	set_the_map(char *path, t_map *map)
{
	char	*line;
	int		i;
	int		fd;
	int		k;
	int		lenght;
	
	i = 0;
	k = count_lenght(path);
	lenght = k / 1000;
	k = k % 1000;
	fd = open (path, O_RDONLY);
	line = short_get_next_line(fd);
	while (line && i < k)
	{
		i++;
		free(line);
		line = short_get_next_line(fd);
	}
	i = 0;
	map->table = malloc(sizeof (char **) * (lenght + 1));
	while (line)
	{
		map->table[i] = ft_strdup(line);
		map->table[i++][ft_strlen(line) - 1] = '\0';
		//printf("%s&\n", map->table[i - 1]);
		free(line);
		line = short_get_next_line(fd);
	}
	map->table[i] = NULL;
	close(fd);
}

void	check_num(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] > '9' || str[i] < '0')
			j++;	
	}
	if (j > 2)
		ft_error(6);
}

void	set_colors_info(t_map *map)
{
	char	*C_color;
	char	*F_color;

	check_num(map->C_info);
	check_num(map->F_info);
	C_color = check_colors_info(map->C_info);
	F_color = check_colors_info(map->F_info);
	map->C_num = ft_atoi(C_color);
	map->F_num = ft_atoi(F_color);
}

void	parsing(char *path, t_map *map)
{
	char	*line;
	int		fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	line = short_get_next_line(fd);
	while (line)
	{
		check_elem(line, map);
		check_info(line, map);
		free(line);
		line = short_get_next_line(fd);
	}
	if (map->C != 1 || map->EA != 1 || map->F != 1 || map->NO != 1 || map->SO != 1 || map->WE != 1)
		ft_error(2);
	check_texture(map);
	set_colors_info(map);
	set_the_map(path, map);
	check_walls(map->table);
	check_contains(map->table);
	check_bug(map->table);
	close(fd);
	// printf("----------------------\n");
	// print_table(map->table);
}



//-------------------------------------------------------------------------------------------//



// if ((i > 0 && (table[i - 1][j] == ' ' || table[i - 1][j] == '\n')) || (table[i + 1][j] && (table[i + 1][j] == ' ' || table[i + 1][j] == '\n')) ||
				// 	(j > 0 && (table[i][j - 1] == ' ' || table[i][j - 1] == '\n')) || (table[i][j + 1] && (table[i][j + 1] == ' ' || table[i][j + 1] == '\n')))
				// 		ft_error(2);