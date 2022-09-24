#include "../cub3D.h"

int	hitwall_horizantal(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
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

int	hitwall(char **table, int x1, int y1)
{
	int	i;
	int	j;

	i = y1 / care;
	j = x1 / care;
	if (i >= ft_strlen_2(table) || i < 0)
		return (1);
	if (j >= ft_strlen(table[i]) || j < 0)
		return (1);
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
