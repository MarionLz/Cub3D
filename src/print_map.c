#include "../include/cub3D.h"

void	create_images(t_data *data)
{
	//compass
	data->img_compass.img = mlx_new_image(data->mlx, WIDTH/10, HEIGHT/10);
	data->img_compass.addr = mlx_get_data_addr(data->img_compass.img, &data->img_compass.bits_per_pixel, &data->img_compass.line_length, &data->img_compass.endian);
	draw_compass(data->img_compass, WIDTH/10, 0x00FF0000);

	//player
	data->img_player.img = mlx_new_image(data->mlx, 10, 10);
	data->img_player.addr = mlx_get_data_addr(data->img_player.img, &data->img_player.bits_per_pixel, &data->img_player.line_length, &data->img_player.endian);
	put_pixel(data->img_player, 10, 0x0000FF);

	//background
	data->img_background.img = mlx_new_image(data->mlx, 10, 10);
	data->img_background.addr = mlx_get_data_addr(data->img_background.img, &data->img_background.bits_per_pixel, &data->img_background.line_length, &data->img_background.endian);
	put_pixel(data->img_background, 10, 0xA9A9A9);

	//wall
	data->img_wall.img = mlx_new_image(data->mlx, WIDTH/10, HEIGHT/10);
	data->img_wall.addr = mlx_get_data_addr(data->img_wall.img, &data->img_wall.bits_per_pixel, &data->img_wall.line_length, &data->img_wall.endian);
	put_pixel(data->img_wall, WIDTH/10, 0xFFFFFF);

	//floor
	data->img_floor.img = mlx_new_image(data->mlx, WIDTH/10, HEIGHT/10);
	data->img_floor.addr = mlx_get_data_addr(data->img_floor.img, &data->img_floor.bits_per_pixel, &data->img_floor.line_length, &data->img_floor.endian);
	put_pixel(data->img_floor, WIDTH/10, 0xA9A9A9);

	//dot_ray
	data->img_dot.img = mlx_new_image(data->mlx, 5, 5);
	data->img_dot.addr = mlx_get_data_addr(data->img_dot.img, &data->img_dot.bits_per_pixel, &data->img_dot.line_length, &data->img_dot.endian);
	put_pixel(data->img_dot, 5, 0x00FF0000);
}

void	print_map(t_data *data, int map[10][10])
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (map[y][x] == 1)
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, x * WIDTH/10, y * HEIGHT/10);
			if (map[y][x] == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->img_floor.img, x * WIDTH/10, y * HEIGHT/10);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->x_player, data->y_player);
}
