#include "../cub3D.h"

int	hitwall_horizantal(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / CARE;
	j = x1 / CARE;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (i > 0 && table[i - 1][j] == '1'))
		return (1);
	return (0);
}

int	hitwall(t_mlxk *window, int x1, int y1, int d)
{
	int	i;
	int	j;
	int	k;

	i = y1 / CARE;
	j = x1 / CARE;
	k = -1;
	if (i >= ft_strlen_2(window->table) || i < 0)
		return (1);
	if (j >= ft_strlen(window->table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (d == 0)
	{
		while (++k < MOVEMENTS)
		{
			x1 -= k * cos(window->angle);
			y1 -= k * sin(window->angle);
			if (window->table[y1 / CARE][x1 / CARE] == '1')
				return (1);
		}
	}
	else
	{
		while (++k < MOVEMENTS)
		{
			x1 += k * cos(window->angle);
			y1 += k * sin(window->angle);
			if (window->table[y1 / CARE][x1 / CARE] == '1')
				return (1);
		}
	}
	return (0);
}

int	hitwall_vertical(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / CARE;
	j = x1 / CARE;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
	if (x1 < 0 || y1 < 0)
		return (1);
	if (table[i][j] == '1' || (j > 0 && table[i][j - 1] == '1'))
		return (1);
	return (0);
}
