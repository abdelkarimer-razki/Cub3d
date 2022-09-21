/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:12:30 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:58:21 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int	x;

	i = -1;
	k = 0;
	while (table[++i])
	{
		j = -1;
		x = 0;
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
				x++;
			}
		}
	}
	if (k > 1)
		ft_error(2);
}

void	check_texture_2(char *line)
{
	char	*exten;
	
	exten = ft_strrchr(&line[2], '.');
	if (!exten || ft_strlen(exten) != 4)
		ft_error(5);
	if (ft_strncmp(exten, ".xpm", 4))
		ft_error(5);	
}

void check_texture(t_map *map)
{
	check_texture_2(map->NO_info);
	check_texture_2(map->SO_info);
	check_texture_2(map->WE_info);
	check_texture_2(map->EA_info);
}

				// if (i > 0 && (table[i - 1][j] == ' ' || table[i - 1][j] == '\n' || table[i - 1][j] == 0))
				// 	ft_error(2);
				// if (table[i + 1][j] && (table[i + 1][j] == ' ' || table[i + 1][j] == '\n' || table[i + 1][j] == 0))
				// 	ft_error(2);
				// if (j > 0 && (table[i][j - 1] == ' ' || table[i][j - 1] == '\n' || table[i][j - 1] == 0))
				// 	ft_error(2);
				// if (table[i][j + 1] && (table[i][j + 1] == ' ' || table[i][j + 1] == '\n' || table[i][j + 1] == 0))
				// 	ft_error(2);