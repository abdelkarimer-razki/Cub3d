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
# define nray 1000
# define pi 3.141592
# define degre (0.0174533 * 60) / 1000 
# define rotates (degre * 30)
# define movements 15
# define angleV (nray * degre)/2

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
	double		x0;
	double		y0;
	double		xv;
	double		yv;
	double		xh;
	double		yh;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	length;
	int		kb;
	int		screenX;
	int		screenY;
	int		rest;
}	t_mlxk;

void	dda(t_mlxk *window, double angle, int i);
void	drawmap(int *map, t_mlxk *window);
void	vision(t_mlxk *window, double angle);
int		hitwall_vertical(int *map, int x1, int y1);
int		hitwall_horizantal(int *map, int x1, int y1);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
int		rgb_to_int(int red, int green, int blue);
int		hitwall(int *map, int x1, int y1);
double	dbt(double x1, double y1, double x0, double y0);
#endif