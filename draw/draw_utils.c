/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:13:32 by aer-razk          #+#    #+#             */
/*   Updated: 2022/12/22 14:54:39 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}

int	rgb_to_int(int opacity, int red, int green, int blue)
{
	return ((opacity * 16777216) + (red * 65536) + (green * 256) + blue);
}

void	shortdistance(t_mlxk *window)
{
	double	dh;
	double	dv;

	dh = dbt(window->xh, window->yh, window->x0, window->y0);
	dv = dbt(window->xv, window->yv, window->x0, window->y0);
	if (dh > dv)
		window->length = dv;
	else
		window->length = dh;
}

int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}
