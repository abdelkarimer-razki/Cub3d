/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:01:44 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/15 11:09:56 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

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
		printf("Error\ninvalid extention for the texture");
	else if (i == 6)
		printf("Error\ninvalid color");
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
	char	*line;
	int		fd;
	int		k;
	int		x;

	k = 0;
	x = 0;
	fd = open(path, O_RDONLY);
	line = short_get_next_line(fd);
	while (line)
	{
		if (check_last_elem(line) == 0 && k == 0)
			x++;
		else if (check_last_elem(line) == 1 || (line[0] == '\n' && k > 0))
			k++;
		free(line);
		line = short_get_next_line(fd);
	}
	return (k * 1000 + x);
}

int	check_intruder(char *line)
{
	int	i;
	int	k;
	int	x;

	i = -1;
	k = 0;
	x = 0;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ' || line[i] == '\t')
			k++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			x++;
	}
	if (k + x != ft_strlen(line))
		ft_error(2);
	if (x > 0)
		return (1);
	return (0);
}

char	*check_colors_info(char *info)
{
	int		i;
	int		n;
	char	*s;
	char	**color;
	
	i = -1;
	s = ft_calloc(1, 1);
	color = ft_split(info, ',');
	while (color[++i])
	{
		n = ft_atoi(color[i]);
		if (n > 255 || n < 0)
			ft_error(6);
	}
	if (i > 3)
		ft_error(6);
	i = -1;
	while (color[++i])
	{
		n = -1;
		while (color[i][++n])
			s = add_char(s, color[i][n]);
	}
	ft_free(color);
	return (s);
}