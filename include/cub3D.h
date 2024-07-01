# ifndef CUB3D
#define CUB3D

#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

//struc for my_mlx_pixel_put
typedef struct  s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_ray
{
	float	r_distance;
	float	r_x;
	float	r_y;
	float	r_angle;
}	t_ray;


typedef struct  s_data
{
	void	*mlx;
	void	*win;
	t_img	img_player;
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_compass;
	t_img	img_background;
	t_img	img_dot;
	int 	x_player;
	int		y_player;
	int		speed_player;
	float	angle_player;
	float	delta_angle;
	t_ray	ray;
}	t_data;

void	init_data(t_data *data);

//player
int		key_hook(int keycode, t_data *data);
void	rotate_player(t_data *data, int dir);
void    move_player(t_data *data, int dir);

void	draw_compass(t_img img, int size, int color);
void	put_pixel(t_img img, int size, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	create_images(t_data *data);
void	print_map(t_data *data, int map[10][10]);

void	init_ray(t_data *data);

int    close_win(void);

# endif