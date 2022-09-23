/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:35:06 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/23 14:23:26 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	set_map_2(map, line, fd, lenght);
	close(fd);
}

char	**texture_parse_2(char *path)
{
	char	**texture;
	int		i;
	char	*line;
	int		fd;

	i = -1;
	fd = open (path, O_RDWR);
	if (fd < 0)
		ft_error(7);
	line = short_get_next_line(fd);
	texture = ft_split(line, ',');
	free(line);
	line = ft_calloc(1, 1);
	while (texture[0][++i])
	{
		if (texture[0][i] >= '0' && texture[0][i] <= '9')
			line = add_char(line, texture[0][i]);
	}
	free(texture[0]);
	texture[0] = ft_strdup(line);
	close(fd);
	return (texture);
}

void	texture_parse(char *path, int *table)
{
	char	**texture;
	int		i;
	int		j;

	i = -1;
	j = -1;
	texture = texture_parse_2(path);
	table = malloc(sizeof(int) * ft_strlen_2(texture));
	while (texture[++i])
		table[++j] = ft_atoi(texture[i]);
	ft_free(texture);
}

void	map_checker(t_map *map)
{
	check_texture(map);
	texture_parse(map->NO_info, map->texture_NO);
	texture_parse(map->SO_info, map->texture_SO);
	texture_parse(map->WE_info, map->texture_WE);
	texture_parse(map->EA_info, map->texture_EA);
	set_colors_info(map);
	check_walls(map->table);
	check_contains(map->table);
	check_bug(map->table);
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
	if (map->C != 1 || map->EA != 1 || map->F != 1
		|| map->NO != 1 || map->SO != 1 || map->WE != 1)
		ft_error(2);
	set_the_map(path, map);
	map_checker(map);
	close(fd);
}
