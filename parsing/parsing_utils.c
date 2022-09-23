/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:01:44 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/22 20:52:01 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
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
	close(fd);
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
		if (line[i] == '1' || line[i] == '0'
			|| line[i] == ' ' || line[i] == '\t')
			k++;
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			x++;
	}
	if (k + x != ft_strlen(line))
		ft_error(2);
	if (x > 0)
		return (1);
	return (0);
}

void	check_colors_info(char *info, int rgb[3])
{
	int		i;
	int		n;
	char	**color;

	i = -1;
	color = ft_split(info, ',');
	while (color[++i])
	{
		n = ft_atoi(color[i]);
		if (n > 255 || n < 0)
			ft_error(6);
		rgb[i] = n;
	}
	if (i > 3)
		ft_error(6);
	ft_free(color);
}

void	check_num(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != ',')
			j++;
		if (str[i] == ',')
			k++;
	}
	if (j > 0)
		ft_error(6);
	if (k > 2)
		ft_error(6);
}
