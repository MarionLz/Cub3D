# ifndef CUB3D
#define CUB3D

#include "../mlx_linux/mlx.h"
#include "../libft/inc/get_next_line.h"
#include "../libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PI 3.14159
#define FOV	60
#define P2 PI/2
#define P3 3*PI/2

# define TILE_SIZE 64
# define SCR_WIDTH 1900
# define SCR_HEIGHT 1000
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define BACK			115
# define RIGHT			100
//azerty :
//# define FORWARD		122
//# define LEFT			113
//qwerty :
# define FORWARD		119
# define LEFT			97

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	char	*path;
}	t_texture;

typedef struct s_ray
{
	double	r_distance;
	double	r_angle;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	int		flag;
}	t_ray;

typedef struct s_player
{
	int		map_x;
	int		map_y;
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
	char		**map;
	int			fd;
	int			nb_rows;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			p_count;
	int			f_count;
	int			c_count;
	double		wall_height;
	int			wall[4][TILE_SIZE * TILE_SIZE];
	t_img		img_screen;
	t_player	player;
	t_texture	texture[4];
	double		delta_angle;
	int			text_y;
	int			text_x;
	unsigned int	color;
	unsigned long	floor_color;
	unsigned long	ceiling_color;
	t_ray		ray;
}	t_data;

int		check_arguments(int ac, char **av);

/* INIT */
void	init_p_angle(t_data *data, char dir);
int		init_player(t_data *data, int x, int y, int count_player);
void	init_data(t_data *data);

/* MOVES */
void	rotate(t_data *data, int direction);
void	move_forward_back(t_data *data, int dir);
void	move_left_right(t_data *data, int dir);

void	draw_compass(t_img img, int width, int height, int color);
void	put_pixel(t_img img, int width, int height, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//void	create_images(t_data *data);
//void	print_map(t_data *data);

void	init_ray(t_data *data);
int		hit_wall(t_data *data, double x, double y, char flag);
double	get_horizontal_distance(t_data *data);
double	get_vertical_distance(t_data *data);

/* ERROR EXIT */
int		display_error(char *error_msg);
void	error_map(t_data *data, char *error_msg);
void	error_file(t_data *data, char *line, char *error_msg);
void	free_map(char **map);
int		close_win(t_data *data);
void	check_counts(t_data *data, char *line);

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

/* PARSE FILE */
int		is_map(char *str);
void	parse_file(char **av, t_data *data);

/* PARSE MAP */
void	parse_map(char *line, t_data *data);

/* RAY */
double	normalize_angle(double angle);
void	raycasting(t_data *data);
double	get_first_step(t_data *data, char dir);
double	get_inter(t_data *data, char dir);

/* DRAW WALL */
void	display_wall(t_data *data, int ray);

/* INIT */
void	init_textures(t_data *data);

/* UTILS */
void	check_floor_ceiling_format(char **colors);
char	*get_path(const char *s);
void	load_path(t_data *data, char *line, int i, int *dir);

/* FREE */
void	free_tab(char **tab);
void	free_all(t_data *data);
void	free_paths(t_data *data, int i);
void	free_mlx(t_data *data);

# endif