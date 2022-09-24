#include "../cub3D.h"

void	vertical_pixel(t_mlxk *window, double d, double y)
{
	window->red = window->map->texture_EA[((((int)d * 32) + ((int)window->yv % 32)) * 3)];
	window->green = window->map->texture_EA[((((int)d * 32) + ((int)window->yv % 32)) * 3) + 1];
	window->blue = window->map->texture_EA[((((int)d * 32) + ((int)window->yv % 32)) * 3) + 2];
	my_mlx_pixel_put(window, window->kb, y, rgb_to_int(0, window->red, window->green, window->blue));
}

void	horizantal_pixel(t_mlxk *window, double d, double y)
{
	window->red = window->map->texture_WE[((((int)d * 32) + ((int)window->xh % 32)) * 3)];
	window->green = window->map->texture_WE[((((int)d * 32) + ((int)window->xh % 32)) * 3) + 1];
	window->blue = window->map->texture_WE[((((int)d * 32) + ((int)window->xh % 32)) * 3) + 2];
	my_mlx_pixel_put(window, window->kb, y, rgb_to_int(0, window->red, window->green, window->blue));
}