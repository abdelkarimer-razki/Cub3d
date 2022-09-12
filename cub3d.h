/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:22:20 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/12 13:19:33 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "math.h"

# define white 16777215
# define yellow 16776960
# define degre 0.0174533
# define angleV 0.523599
# define care 50

int karim;
int colors[9];


typedef struct mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	**buffer;
	char	*addr;
	int		map[64];
	double	angle;
	int		x0;
	int		y0;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		rest;
}	t_mlxk;


typedef struct s_map
{
	char	**table;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		F;
	int		C;
	char	*NO_info;
	char	*SO_info;
	char	*WE_info;
	char	*EA_info;
	char	*F_info;
	char	*C_info;
	char	player;
}	t_map;


//utils
void	ft_error(int i);
char	*ft_strrchr(const char *s, int c);
int	    ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *source);
char	*add_char(char *str, char c);
char	*ft_strjoin(char const *s1, char *s2);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
char	**ft_realloc(char **table, int size);
void	*ft_free(char **c);

//parse
void	parsing(char *path, t_map *map);
void	check_exten(char *path, int ac);
char	*short_get_next_line(int fd);
int		check_elem(char *line, t_map *map);
int		check_elem_2(char *line);
void	check_info(char *line, t_map *map);

//draw
int		controlplayer(int key, t_mlxk *params, t_map *map2);
void	dda(t_mlxk window, int length, double angle);
void	drawmap(t_mlxk window, t_map * map);
void	vision(t_mlxk window, int length, double angle);
int		hitwall(int *map, int x1, int y1);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);

#endif


// void	dda(t_mlxk *window, float length, double angle, int i);
// void	drawmap(int *map, t_mlxk *window);
// void	vision(t_mlxk *window, int length, double angle);
// int		hitwall(int *map, int x1, int y1);