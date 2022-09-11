/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:25:49 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/09 13:48:52 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*d;

	d = s;
	i = ft_strlen(s);
	while (*s && i)
	{
		i--;
		s++;
	}
	while (i <= (int)ft_strlen(d))
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s--;
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int			i;
	unsigned char	*x;
	unsigned char	*y;

	i = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (x != NULL || y != NULL)
	{
		while ((x[i] != '\0' || y[i] != '\0')
			&& i != n)
		{
			if (x[i] != y[i])
				return (x[i] - y[i]);
			i++;
		}
	}
	return (0);
}

char	*ft_strdup(const char *source)
{
	char	*s;
	int		i;

	i = 0;
	while (source[i])
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (source[i] != '\0')
	{
		s[i] = source[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*add_char(char *str, char c)
{
	char	*s;
	int		j;

	j = -1;
	s = ft_calloc(ft_strlen(str) + 2, 1);
	if (!s)
		return (0);
	while (str[++j])
		s[j] = str[j];
	if (j == -1)
		j = 0;
	s[j++] = c;
	s[j] = 0;
	free(str);
	return (s);
}

char	*short_get_next_line(int fd)
{
    char    buff[1];
	char	*line;

	if (fd < 0)
		return (NULL);
	line = ft_calloc(1, 1);
	while (read(fd, buff, 1) == 1)
	{
		line = add_char(line, buff[0]);
		if (buff[0] == '\n')
			break ;
	}
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}