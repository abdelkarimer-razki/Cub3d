/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:35:06 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/11 17:49:05 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_error(int i)
{
	if (i == 1)
		printf("Error\ninvalid extensions\n");
	else if (i == 2)
		printf("Error\ninvalid map, check your map\n");
	else if (i == 3)
		printf("Error\nyour file is not exist\n");
	else if (i == 4)
		printf("Error\ninvalid parametre\n");
	exit(0);
}

int	check_last_elem(char *line)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	j = 0;
	x = 0;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			j++;
		else if (line[i] == ' ')
			x++;	
	}
	if (x + j > i / 2)
	{
		if (x + j == i - 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int	count_lenght(char *path)
{
	int		i;
	char	*line;
	int		fd;
	int		k;
	int		x;

	i = 0;
	k = 0;
	x = 0;
	fd = open(path, O_RDONLY);
	line = short_get_next_line(fd);
	while (line)
	{
		if (check_last_elem(line) == 0 && k == 0)
			x++;
		if (check_last_elem(line) == 0)
			i++;
		else if (check_last_elem(line) == 1)
			k++;
		free(line);
		line = short_get_next_line(fd);
	}
	if (x != i)
		ft_error(3);
	return (k * 1000 + x);
}

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
		map->table[i++][ft_strlen(line) - 1] = 0;
		free(line);
		line = short_get_next_line(fd);	
	}
	map->table[i] = NULL;
}

void	check_walls_top_and_bottom(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error(2);
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	check_walls_top_and_bottom(map->table[i]);
	while (map->table[++i + 1])
	{
		j = 0;
		while (map->table[i][j])
		{
			while (map->table[i][j] == ' ')
				j++;
			if (map->table[i][j] == '1' && map->table[i][ft_strlen(map->table[i]) - 1] == '1')
				break;
			else
				ft_error(2);
		}
	}
	check_walls_top_and_bottom(map->table[i]);
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
	set_the_map(path, map);
	check_walls(map);
}