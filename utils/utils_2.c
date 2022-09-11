/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:13:37 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/08 14:52:34 by bboulhan         ###   ########.fr       */
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

void	*ft_free(char **c)
{
	int	i;

	i = 0;
	if (!c)
		return (NULL);
	while (c[i])
		i++;
	while (--i >= 0)
		free(c[i]);
	free(c);
	return (NULL);
}