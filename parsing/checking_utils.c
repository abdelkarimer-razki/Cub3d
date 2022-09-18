/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:42:47 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:47:45 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

void	check_exten(char *path, int ac)
{
	char	*exten;
	int		fd;

	if (ac != 2)
		ft_error(4);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	exten = ft_strrchr(path, '.');
	if (!exten || ft_strlen(exten) != 4)
		ft_error(1);
	if (ft_strncmp(exten, ".cub", 4))
		ft_error(1);
	close(fd);
}

int	check_elem(char *line, t_map *map)
{
	if (!ft_strncmp(line, "NO ", 3))
		map->NO++;
	else if (!ft_strncmp(line, "SO ", 3))
		map->SO++;
	else if (!ft_strncmp(line, "WE ", 3))
		map->WE++;
	else if (!ft_strncmp(line, "EA ", 3))
		map->EA++;
	else if (!ft_strncmp(line, "F ", 2))
		map->F++;
	else if (!ft_strncmp(line, "C ", 2))
		map->C++;
	else
		return (0); 
	return (1);
}

int	check_elem_2(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		return (2);
	else if (!ft_strncmp(line, "WE ", 3))
		return (3);
	else if (!ft_strncmp(line, "EA ", 3))
		return (4);
	else if (!ft_strncmp(line, "F ", 2))
		return (5);
	else if (!ft_strncmp(line, "C ", 2))
		return (6);
	else
		return (0);
}

void	check_info(char *line, t_map *map)
{
	int		i;
	char	*s;

	i = 1;
	s = ft_calloc(1, 1);
	if (check_elem_2(line) > 0)
	{
		while (line[++i])
		{
			if ((line[i] == '.' && line[ i + 1] && line[i + 1] == '/') || check_elem_2(line) > 4)
			{
				while (line[i] && line[i] != '\n')
					s = add_char(s, line[i++]);
			}
		}
		if (check_elem_2(line) == 1)
			map->NO_info = ft_strdup(s);
		else if (check_elem_2(line) == 2)
			map->SO_info = ft_strdup(s);
		else if (check_elem_2(line) == 3)
			map->WE_info = ft_strdup(s);
		else if (check_elem_2(line) == 4)
			map->EA_info = ft_strdup(s);
		else if (check_elem_2(line) == 5)
			map->F_info = ft_strdup(s);
		else if (check_elem_2(line) == 6)
			map->C_info = ft_strdup(s);
	}
	free(s);
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