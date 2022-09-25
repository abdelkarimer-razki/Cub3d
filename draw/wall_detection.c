/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:16:31 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:16:32 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	hitwall_horizantal(char **table, double x1, double y1)
{
	double	i;
	double	j;

	i = y1 / CARE;
	j = x1 / CARE;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[(int)i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[(int)i][(int)j] == '1'
		|| (i > 0 && table[(int)i - 1][(int)j] == '1'))
		return (1);
	return (0);
}

int	hitwall(t_mlxk *window, double x1, double y1, int d)
{
	int	k;

	k = MOVEMENTS;
	if (y1 / CARE >= ft_strlen_2(window->table) || y1 / CARE < 0)
		return (1);
	if (x1 / CARE >= ft_strlen(window->table[(int)y1 / CARE]) || x1 / CARE < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	while (--k >= 0)
	{
		if (d == 0)
		{
			x1 -= k * cos(window->angle);
			y1 -= k * sin(window->angle);
		}
		else
		{
			x1 += k * cos(window->angle);
			y1 += k * sin(window->angle);
		}
		if (window->table[(int)y1 / CARE][(int)x1 / CARE] == '1')
			return (1);
	}
	return (0);
}

int	hitwall_lite(t_mlxk *window, double x1, double y1)
{
	double	i;
	double	j;

	i = y1 / CARE;
	j = x1 / CARE;
	if (i >= ft_strlen_2(window->table) || i < 0)
		return (1);
	if (j >= ft_strlen(window->table[(int)i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (window->table[(int)i][(int)j] == '1')
		return (1);
	return (0);
}

int	hitwall_vertical(char **table, double x1, double y1)
{
	double	i;
	double	j;

	i = y1 / CARE;
	j = x1 / CARE;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[(int)i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[(int)i][(int)j] == '1'
		|| (j > 0 && table[(int)i][(int)j - 1] == '1'))
		return (1);
	return (0);
}
