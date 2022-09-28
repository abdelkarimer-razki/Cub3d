/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:13:37 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/25 18:55:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*x;
	int		y;

	y = num * size;
	x = malloc(y);
	if (!x)
		return (NULL);
	while (y--)
		x[y] = 0;
	return (x);
}

char	**ft_realloc(char **table, int size)
{
	char	**t;
	int		i;

	i = 0;
	t = malloc(sizeof(char *) * (size + 1));
	if (!t)
		return (NULL);
	while (table[i])
	{
		t[i] = ft_strdup(table[i]);
		i++;
	}
	t[i] = "realloc";
	t[size] = NULL;
	ft_free(table);
	return (t);
}

int	ft_atoi(const char *str)
{
	char		*c;
	size_t		k;
	size_t		m;

	c = (char *)str;
	m = 1;
	k = 0;
	while (*c == ' ' || *c == '\n'
		|| *c == '\t' || *c == '\r'
		|| *c == '\f' || *c == '\v' )
	{
		c++;
	}
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			m = m * -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		k = (*c - 48) + k * 10;
		c++;
	}
	return ((int)(k * m));
}

void	remove_space(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[i - 1] == ' ')
	{
		while (--i > 0)
		{
			if (line[i] != ' ')
			{
				line[i + 1] = 0;
				break ;
			}
		}
	}
}
