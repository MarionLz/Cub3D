/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:58:43 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 15:32:04 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PI 	3.14159
# define FOV	60

# define BUFFER_SIZE 42

# define TILE_SIZE 		64
# define SCR_WIDTH 		1900
# define SCR_HEIGHT 	1000
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
	int		p_x;
	int		p_y;
	float	fov_rad;
	int		p_speed;
	double	p_angle;
}	t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	char			**map;
	int				fd;
	int				nb_rows;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				p_count;
	int				f_count;
	int				c_count;
	double			wall_height;
	int				wall[4][TILE_SIZE * TILE_SIZE];
	t_img			img_screen;
	t_player		player;
	t_texture		texture[4];
	double			delta_angle;
	int				text_y;
	int				text_x;
	char			*stash;
	unsigned int	color;
	unsigned long	floor_color;
	unsigned long	ceiling_color;
	t_ray			ray;
}	t_data;

/* MAIN */
void	init_data(t_data *data);
int		check_arguments(int ac, char **av);

/* PARSE FILE */
void	parse_textures(char *line, t_data *data);
void	convert_color(t_data *data, char **colors, char *line, int flag);
void	parse_floor_ceiling(char *line, t_data *data);
int		parse_blocs(char *line, t_data *data, int file_blocs);
void	parse_file(char **av, t_data *data);

/* PARSE MAP */
bool	empty_line(char *line);
bool	closed_map(t_data *data, int x, int y);
void	check_map(t_data *data);
void	parse_map(char *line, t_data *data);

/* PARSING UTILS 1 */
void	check_floor_ceiling_format(char **colors, t_data *data, char *line);
char	*get_path(const char *s);
void	load_path(t_data *data, char *line, int i, int *dir);
void	init_p_angle(t_data *data, char dir);
int		init_player(t_data *data, int x, int y, int count_player);

/* PARSING UTILS 2 */
void	check_counts(t_data *data, char *line);
int		is_map(char *str);

/* GET NEXT LINE */
char	*get_next_line(int fd, t_data *data);

/* INIT TEXTURES */
void	init_texture_data(t_data *data);
void	*convert_img(t_data *data, char *path, int i);
char	*get_data_address(t_texture *texture);
void	store_textures_pixels(t_data *data, int i);
void	init_textures(t_data *data);

/* KEY */
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		close_win(t_data *data);

/* MOVES */
void	rotate(t_data *data, int direction);
void	move_forward_back(t_data *data, int dir);
void	move_left_right(t_data *data, int dir);

/* RAYCASTING */
int		hit_wall(t_data *data, double x, double y, char flag);
double	get_horizontal_distance(t_data *data);
double	get_vertical_distance(t_data *data);
void	get_shorter_distance(t_data *data);
void	raycasting(t_data *data);

/* RAYCASTING UTILS */
double	normalize_angle(double angle);
double	get_first_step(t_data *data, char dir);
double	get_inter(t_data *data, char dir);

/* DRAW PIXELS*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/* DRAW WALL */
int		get_texture(t_data *data);
void	get_text_x(t_data *data, int text_nb);
void	draw_wall(t_data *data, int top_pix, int bottom_pix, int ray);
void	draw_floor_and_ceiling(t_data *data, int ray, int bottom_pix,
			int top_pix);
void	display_wall(t_data *data, int ray);

/* ERROR EXIT */
int		display_error(char *error_msg);
void	error_map(t_data *data, char *error_msg);
void	error_file(t_data *data, char *line, char *error_msg);
void	error_textures(t_data *data, char *error_msg, char *line);
void	error_no_map(t_data *data, char *error_msg);

/* FREE */
void	free_tab(char **tab);
void	free_paths(t_data *data);
void	free_all(t_data *data);
void	free_mlx(t_data *data);

#endif