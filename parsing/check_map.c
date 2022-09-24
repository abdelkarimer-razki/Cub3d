/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:12:30 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/23 14:12:01 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_walls(char **table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_walls_top_and_bottom(table[i]);
	while (table[++i + 1])
	{
		j = 0;
		while (table[i][j])
		{
			while (table[i][j] == ' ')
				j++;
			if (table[i][j] == '1' && table[i][ft_strlen(table[i]) - 1] == '1')
				break ;
			else
				ft_error(2);
		}
	}
	check_walls_top_and_bottom(table[i]);
}

void	check_bug(char **table)
{
	int	i;
	int	j;

	i = -1;
	while (table[++i])
	{
		j = -1;
		while (table[i][++j])
		{
			if (table[i][j] == '0' || table[i][j] == 'N' ||
				table[i][j] == 'S' || table[i][j] == 'W' || table[i][j] == 'E')
			{
				if ((i > 0 && (table[i - 1][j] == ' ' || table[i - 1][j] == '\n'
					|| table[i - 1][j] == 0)) ||
					(table[i + 1][j] && (table[i + 1][j] == ' ' ||
					table[i + 1][j] == '\n' || table[i + 1][j] == 0)) ||
					(j > 0 && (table[i][j - 1] == ' ' ||
					table[i][j - 1] == '\n' || table[i][j - 1] == 0)) ||
					(table[i][j + 1] && (table[i][j + 1] == ' ' ||
					table[i][j + 1] == '\n' || table[i][j + 1] == 0)))
					ft_error(2);
			}
		}
	}
}

void	check_contains(char **table)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (table[++i])
	{
		j = -1;
		k += check_intruder(table[i]);
		while (table[i][++j])
		{
			if (table[i][j] == ' ')
			{
				if (table[i][j + 1] && (table[i][j + 1] != ' ' &&
					table[i][j + 1] != '1'))
					ft_error(2);
				else if (j > 0 && (table[i][j - 1] != ' '
					&& table[i][j - 1] != '1'))
					ft_error(2);
			}
		}
	}
	if (k > 1)
		ft_error(2);
}

void	set_colors_info(t_map *map)
{
	check_num(map->c_info);
	check_num(map->f_info);
	check_colors_info(map->c_info, map->c_num);
	check_colors_info(map->f_info, map->f_num);
}

void	set_map_2(t_map *map, char *line, int fd, int lenght)
{
	int	i;

	i = 0;
	map->table = malloc(sizeof (char **) * (lenght + 1));
	while (line)
	{
		map->table[i] = ft_strdup(line);
		map->table[i++][ft_strlen(line) - 1] = '\0';
		free(line);
		line = short_get_next_line(fd);
	}
	map->table[i] = NULL;
}
