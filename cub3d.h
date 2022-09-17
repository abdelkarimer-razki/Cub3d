/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:22:20 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/16 16:03:41 by bboulhan         ###   ########.fr       */
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
# define nray 3
# define pi 3.141592
# define degre 0.0174533
# define rotates degre
# define movements 15
# define angleV (nray * degre)/2
# define care 50

int karim;
int colors[9];

typedef struct s_map
{
	char	**table;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		F;
	int		C;
	int		F_num;
	int		C_num;
	char	*NO_info;
	char	*SO_info;
	char	*WE_info;
	char	*EA_info;
	char	*F_info;
	char	*C_info;
	char	player;
}	t_map;

typedef struct mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	**buffer;
	char	*addr;
	char	**table;
	t_map	*map;
	double	angle;
	double		x0;
	double		y0;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		rest;
	double x9;
	double y9;
}	t_mlxk;



void	print(t_map *map);


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
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

//parse
void	parsing(char *path, t_map *map);
void	check_exten(char *path, int ac);
char	*short_get_next_line(int fd);
int		check_elem(char *line, t_map *map);
int		check_elem_2(char *line);
void	check_info(char *line, t_map *map);
int		check_last_elem(char *line);
int		count_lenght(char *path);
int		check_intruder(char *line);
void	check_walls_top_and_bottom(char *line);
void	check_walls(char **table);
void 	check_bug(char **table);
void 	check_contains(char **table);
void 	check_texture(t_map *map);
char	*check_colors_info(char *info);


//draw
void	drawmap(t_map *map, t_mlxk *window);
void	dda(t_mlxk *window, double length, double angle, int i);
int	ft_exit(void *arg);
void	vision(t_mlxk *window, double length, double angle, t_map *map);
int usemouse(int x, int y, t_mlxk *params,t_map *map);
int	controlplayer(int key, t_mlxk *params);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
void	ray_to_3d(t_mlxk *window, double length, int i, double x1, double y1);
void	horizontal_lines(double *x1, double *y1, t_mlxk *window, double angle);
int	hitwall(char **table, int x1, int y1);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
int		rgb_to_int(int red, int green, int blue);

#endif


// void	dda(t_mlxk *window, float length, double angle, int i);
// void	drawmap(int *map, t_mlxk *window);
// void	vision(t_mlxk *window, int length, double angle);
// int		hitwall(int *map, int x1, int y1);