/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:01:10 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/24 17:02:45 by bboulhan         ###   ########.fr       */
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
	else if (i == 5)
		printf("Error\ninvalid extention for the texture\n");
	else if (i == 6)
		printf("Error\ninvalid color\n");
	else if (i == 7)
		printf("Error\ntexture file is not exist\n");
	exit(1);
}

void	check_texture_2(char *line)
{
	char	*exten;

	exten = ft_strrchr(&line[2], '.');
	if (!exten || ft_strlen(exten) != 4)
		ft_error(5);
	if (ft_strncmp(exten, ".ppm", 4))
		ft_error(5);
}

void	check_texture_file(char *path)
{
	int	fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		ft_error(7);
	close(fd);
}

void	check_texture(t_map *map)
{
	check_texture_2(map->NO_info);
	check_texture_2(map->SO_info);
	check_texture_2(map->WE_info);
	check_texture_2(map->EA_info);
	check_texture_file(map->NO_info);
	check_texture_file(map->SO_info);
	check_texture_file(map->WE_info);
	check_texture_file(map->EA_info);
}

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
