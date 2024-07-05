# ifndef CUB3D
#define CUB3D

#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159
#define FOV	60

//# define S_WIDTH 1900 // screen Width
//# define S_HEIGHT 1000 // screen Heigth
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD		122		//119(qwerty)
# define BACK			115
# define RIGHT			100
# define LEFT			113		//97(qwerty)

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
	double	r_distance;

	double	r_x;
	double	r_y;
	double	r_angle;
}	t_ray;

typedef struct s_player
{
	int 	p_x;
	int		p_y;
	float	fov_rad;
	int		p_speed;
	double	p_angle;
}	t_player;

typedef struct  s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			nb_colomn;
	int			nb_rows;
	int			width_square;
	int			height_square;
	int			map[10][10];
	t_img		img_player;
	t_img		img_wall;
	t_img		img_floor;
	t_img		img_compass;
	t_img		img_background;
	t_img		img_dot;
	t_player	player;
	double		delta_angle;
	t_ray		ray;
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
void	print_map(t_data *data);

void 	init_ray(t_data *data);

int    close_win(void);

/* DRAW WALL */
void	display_wall(t_data *data);

# endif