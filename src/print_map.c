#include "../include/cub3D.h"

/* void	create_images(t_data *data)
{
	//compass
	data->img_compass.img = mlx_new_image(data->mlx, data->width_square, data->height_square);
	data->img_compass.addr = mlx_get_data_addr(data->img_compass.img, &data->img_compass.bits_per_pixel, &data->img_compass.line_length, &data->img_compass.endian);
	draw_compass(data->img_compass, data->width_square, data->height_square, 0x00FF0000);

	//player
	data->img_player.img = mlx_new_image(data->mlx, 10, 10);
	data->img_player.addr = mlx_get_data_addr(data->img_player.img, &data->img_player.bits_per_pixel, &data->img_player.line_length, &data->img_player.endian);
	put_pixel(data->img_player, 10, 10, 0x0000FF);

	//background player
	data->img_background.img = mlx_new_image(data->mlx, 10, 10);
	data->img_background.addr = mlx_get_data_addr(data->img_background.img, &data->img_background.bits_per_pixel, &data->img_background.line_length, &data->img_background.endian);
	put_pixel(data->img_background, 10, 10, 0xA9A9A9);

	//wall
	data->img_wall.img = mlx_new_image(data->mlx, data->width_square, data->height_square);
	data->img_wall.addr = mlx_get_data_addr(data->img_wall.img, &data->img_wall.bits_per_pixel, &data->img_wall.line_length, &data->img_wall.endian);
	put_pixel(data->img_wall, data->width_square, data->height_square, 0xFFFFFF);

	//floor
	data->img_floor.img = mlx_new_image(data->mlx, data->width_square, data->height_square);
	data->img_floor.addr = mlx_get_data_addr(data->img_floor.img, &data->img_floor.bits_per_pixel, &data->img_floor.line_length, &data->img_floor.endian);
	put_pixel(data->img_floor, data->width_square, data->height_square, 0xA9A9A9);

	//dot_ray
	data->img_dot.img = mlx_new_image(data->mlx, 5, 5);
	data->img_dot.addr = mlx_get_data_addr(data->img_dot.img, &data->img_dot.bits_per_pixel, &data->img_dot.line_length, &data->img_dot.endian);
	put_pixel(data->img_dot, 5, 5, 0x00FF0000);
} */

/* void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (data->map[y][x] == 1)
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, x * data->width_square, y * data->height_square);
			if (data->map[y][x] == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->img_floor.img, x * data->width_square, y * data->height_square);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->player.p_x, data->player.p_y);
} */
