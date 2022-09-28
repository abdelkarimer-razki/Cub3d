/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:22:20 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/25 19:52:49 by bboulhan         ###   ########.fr       */
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
# define SCREENX 800
# define SCREENY 500
# define PI 3.141592
# define MOVEMENTS 10
# define CARE 32

typedef struct s_map
{
	char	**table;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		fc;
	int		cc;
	char	*no_info;
	char	*so_info;
	char	*we_info;
	char	*ea_info;
	char	*f_info;
	char	*c_info;
	int		f_num[3];
	int		c_num[3];
	int		*texture_no;
	int		*texture_so;
	int		*texture_we;
	int		*texture_ea;
}	t_map;

typedef struct mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	t_map	*map;
	double	angle;
	double	x0;
	double	y0;
	double	xv;
	double	yv;
	double	xh;
	double	yh;
	double	degre;
	double	anglev;
	double	rotates;
	int		tl;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		up;
	double	length;
	int		kb;
	int		red;
	int		green;
	int		blue;
	int		screeny;
}	t_mlxk;

//utils
void	ft_error(int i);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *source);
char	*add_char(char *str, char c);
char	*ft_strjoin(char const *s1, char *s2);
int		ft_strlen(const char *s);
void	person(t_mlxk *window);
void	*ft_calloc(size_t num, size_t size);
char	**ft_realloc(char **table, int size);
void	*ft_free(char **c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strlen_2(char **s);
char	*ft_strtrim(char *s1, char *set);
//parsing
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
void	check_bug(char **table);
void	check_contains(char **table);
void	check_texture(t_map *map);
void	check_colors_info(char *info, int rgb[3]);
void	check_num(char *str);
int		*texture_parse(char *path);
void	set_colors_info(t_map *map);
void	set_map_2(t_map *map, char *line, int fd, int lenght);
void	remove_space(char *line);
//draw
void	drawmap(t_mlxk *window);
void	dda(t_mlxk *window, double angle, int i);
void	horizantal_pixel(t_mlxk *window, double d, double y, double angle);
void	vertical_pixel(t_mlxk *window, double d, double y, double angle);
int		hitwall_vertical(char **table, double x1, double y1, int length);
int		hitwall_horizantal(char **table, double x1, double y1, int length);
int		ft_exit(void *arg);
void	camera_left(t_mlxk *params);
void	move_forward(t_mlxk *params);
void	move_backward(t_mlxk *params);
void	camera_right(t_mlxk *params);
void	camera_up(t_mlxk *params);
void	camera_down(t_mlxk *params);
void	vision(t_mlxk *window, double angle);
int		controlplayer(int key, t_mlxk *params);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
void	ray_to_3d(t_mlxk *window, double length, int i, double angle);
void	horizontal_lines(t_mlxk *window, double angle);
int		hitwall(t_mlxk *window, double x1, double y1, int d);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
int		rgb_to_int(int opacity, int red, int green, int blue);
void	shortdistance(t_mlxk *window);
//void	shortdistance(t_mlxk *window, double angle);
double	dbt(double x1, double y1, double x0, double y0);
//double	dbt(double y1, double y0, double angle);
void	move_right(t_mlxk *params);
void	move_left(t_mlxk *params);
int		hitwall_lite(t_mlxk *window, double x1, double y1);
void	vertical_lines(t_mlxk *window, double angle);
void	my_mlx_pixel_put1(t_mlxk *data, int x, int y, int color);
void	my_mlx_pixel_put2(t_mlxk *data, int x, int y, int color);
#endif
