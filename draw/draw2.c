/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:10 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/19 12:31:41 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

int	hitwall_horizantal(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table))
		return(1);
	if (j >= ft_strlen(table[i]))
		return(1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (i > 0 && table[i - 1][j] == '1'))
		return (1);
	return (0);
}

int hitwall(char **table, int x1, int y1)
{
	int	i;
	int	j;
	
	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table))
		return(1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1')
		return (1);
	return (0);
}

int	hitwall_vertical(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table))
		return(1);
	// if (j >= ft_strlen(table[i]))
	// 	return(1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (j > 0 && table[i][j - 1] == '1'))
		return (1);
	return (0); 
}

void	vertical_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
	double	x0;
	double	y0;
	double	sy;
	
	x0 = (int)(window->x0/ care) * care;
	if (angle < pi / 2 || angle > 1.5 * pi)
		x0 += care;
	y0 = window->y0 + tan(angle) * (x0 - window->x0);
	sy = tan(angle) * care;
	if (angle < pi && angle > 0 && sy < 0)
		sy *= -1;
	else if (!(angle < pi && angle > 0) && sy > 0)
		sy *= -1;
	while (hitwall_vertical(window->table, x0, y0) == 0)
	{
		if (angle < pi / 2 || angle > 1.5 * pi)
			x0 += care;
		else
			x0 -= care;
		y0 += sy;
	}
	(*x1) = x0;
	(*y1) = y0;
}

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}

void	shortdistance(double *x1, double *y1, t_mlxk *window)
{
	if (dbt(window->xh, window->yh, window->x0, window->y0) > dbt(window->xv, window->yv, window->x0, window->y0))
	{
		*x1 = window->xv;
		*y1 = window->yv;
	}
	else
	{
		*x1 = window->xh;
		*y1 = window->yh;
	}
	window->length = dbt(*x1, *y1, window->x0, window->y0);
}


void	horizontal_lines(double *x1, double *y1, t_mlxk *window, double angle)
{
    double x0;
	double y0;

	y0 = (int)(window->y0/ care) * care;
	if (angle < pi && angle > 0)
		y0 += care;
	x0 = window->x0 + ((y0 - window->y0) / tan(angle));
	float sx = care / tan(angle);
	if (!(angle < pi / 2 || angle > 1.5 * pi) && sx > 0)
		sx *= -1;
	else if ((angle < pi / 2 || angle > 1.5 * pi) && sx < 0)
		sx *= -1;
	while (hitwall_horizantal(window->table, x0, y0) == 0)
	{
		if (angle < pi && angle > 0)
			y0 += care;
		else
			y0 -= care;
		x0 += sx;
	}
	(*x1) = x0;
	(*y1) = y0;
}

int	rgb_to_int(int red, int green, int blue)
{
	return ((red * 65536) + (green * 256) + blue);
}

void	ray_to_3d(t_mlxk *window, double length, int i)
{
	int lineH;
	double	y;
	double x;

	if (i <= (nray / 2) - 1)
		length *= cos(angleV - (((i % (nray / 2)) * degre)));
	else if(i >= (nray / 2))
		length *= cos((i % (nray / 2)) * degre);
	lineH = 50 * 500 / length;
	if (lineH > window->screenY)
		lineH = window->screenY;
	y = (window->screenY - lineH) / 2;
	while ((int)y < lineH + (window->screenY - lineH) / 2)
	{
		x = window->kb;
		while ((int)x < 1 + window->kb)
		{
			if (window->length == dbt(window->xh, window->yh, window->x0, window->y0))
				my_mlx_pixel_put(window, x, y, colors[3]);
			else if (window->length == dbt(window->xv, window->yv, window->x0, window->y0))
				my_mlx_pixel_put(window, x, y, colors[5]);
			x++;
		}
		y++;
	}
	window->kb += 1;
}





















//-----------------------------------------------------------------------------------------------------------//


// void	ray_to_3d(t_mlxk *window, double length, int i, double x1, double y1)
// {
// 	int lineH;
// 	double	y;
// 	double x;
// 	int lineA;

// 	int	d;
// 	int e;
// 	d = 0;
// 	while (d < 32)
// 	{
// 		e = 0;
// 		while (e < 32)
// 		{
// 			int pixel = (d * 32 + e) * 3;
// 			int red = textures[pixel + 0];
// 			int green = textures[pixel + 1];
// 			int blue = textures[pixel + 2];
// 			my_mlx_pixel_put(window, e, d, rgb_to_int(red, green, blue));
// 			e++;
// 		}
// 		d++;
// 	}
// 	//printf("x1 : %f | y1 : %f | length : %f\n", x1, y1, length);
// 	if (i <= (nray / 2) - 1)
// 		length *= cos(angleV - (((i % (nray / 2)) * degre)));
// 	else if(i >= (nray / 2))
// 		length *= cos((i % (nray / 2)) * degre);
// 		//(void) i;
// 	lineH = 50 * 500 / length;
// 	if (lineH > 500)
// 		lineH = 500;
// 	y = (500 - lineH) / 2;
// 	x = 0;
// 	lineA = 1000 / nray;
// 	while ((int)y < lineH + (500 - lineH) / 2)
// 	{
// 		x = karim;
// 		while ((int)x < lineA + karim)
// 		{
// 			/*if ((i > 0 && (int)window->x9 == (int)x1 && (int)window->y9 != (int)y1 && (int)(x1 + 0.01) % care == 0 && (int)window->y9 != (int)y1))
// 				my_mlx_pixel_put(window, x, y, colors[3]);
// 			else if (i > 0 && (int)window->y9 == (int)y1 && (int)(y1 + 0.01) % care == 0)
// 				my_mlx_pixel_put(window, x, y, colors[6]);*/
// 			/*if (((int)(x1 + 0.01) % care == 0) && ((int)(y1 + 0.01) % care == 0))
// 			{
// 				if ((x1 - (int)x1) < 0.1)
// 					my_mlx_pixel_put(window, x, y, colors[6]);
// 				else
// 					my_mlx_pixel_put(window, x, y, colors[3]);
// 			}
// 			else if ((int)(x1 + 0.01) % care == 0)
// 				my_mlx_pixel_put(window, x, y, colors[3]);
// 			else
// 				my_mlx_pixel_put(window, x, y, colors[6]);*/
// 			/*if (lineH <= 500 && lineH >= 445)
// 				my_mlx_pixel_put(window, x, y, colors[0]);
// 			if (lineH <= 444 && lineH >= 389)
// 				my_mlx_pixel_put(window, x, y, colors[1]);
// 			if (lineH <= 388 && lineH >= 333)
// 				my_mlx_pixel_put(window, x, y, colors[2]);
// 			if (lineH <= 332 && lineH >= 277)
// 				my_mlx_pixel_put(window, x, y, colors[3]);
// 			if (lineH <= 276 && lineH >= 221)
// 				my_mlx_pixel_put(window, x, y, colors[4]);
// 			if (lineH <= 220 && lineH >= 165)
// 				my_mlx_pixel_put(window, x, y, colors[5]);
// 			if (lineH <= 164 && lineH >= 109)
// 				my_mlx_pixel_put(window, x, y, colors[6]);
// 			if (lineH <= 108 && lineH >= 53)
// 				my_mlx_pixel_put(window, x, y, colors[7]);
// 			if (lineH <= 52)
// 				my_mlx_pixel_put(window, x, y, colors[8]);*/
// 			//my_mlx_pixel_put(window, x, y,);	
// 			x++;
// 		}
// 		y++;
// 	}
// 	window->x9 = x1;
// 	window->y9 = y1;
// 	karim += lineA;
// }