#ifndef CUB3D_H
# define CUB3D_H
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<mlx.h>
# define white 16777215
# define yellow 16776960

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

void	dda(t_mlxk *window, int length, double angle);
void	drawmap(int *map, t_mlxk *window);
void	vision(t_mlxk *window, int length, double angle);
int		hitwall(int *map, int x1, int y1);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
#endif