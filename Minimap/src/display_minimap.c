#include "../include/cub3D.h"

void	init_background_compass(t_data *data)
{
	int	x;
	int	y;
	
	data->img_background.img = mlx_new_image(data->mlx, data->width_square, data->height_square);
	data->img_background.addr = mlx_get_data_addr(data->img_background.img, &data->img_background.bits_per_pixel, &data->img_background.line_length, &data->img_background.endian);
	x = 0;
	while(x < data->width_square)
	{
		y = 0;
		while (y < data->height_square)
		{
			my_mlx_pixel_put(&data->img_background, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	display_compass(t_data *data)
{
	int	x;
	int	y;
	
	y = data->height_square / 2;
	x = data->width_square / 2;
	data->img_compass.img = mlx_new_image(data->mlx, data->width_square, data->height_square);
	data->img_compass.addr = mlx_get_data_addr(data->img_compass.img, &data->img_compass.bits_per_pixel, &data->img_compass.line_length, &data->img_compass.endian);
	while (x < data->width_square)
	{
		my_mlx_pixel_put(&data->img_minimap, x, y, 0x00FF0000);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	init_background_compass(data);
}

void	display_tiles(t_data *data, int x_map, int y_map, int color)
{
	int	x;
	int	y;
	int	x_end;
	int y_end;

	x_end = x_map * data->width_square + data->width_square;
	y_end = y_map * data->height_square + data->height_square;
	x = x_map * data->width_square + 1;
	while (x < x_end - 1)
	{
		y = y_map * data->height_square + 1;
		while (y < y_end - 1)
		{
			my_mlx_pixel_put(&data->img_minimap, x, y, color);
			y++;
		}
		x++;
	}
}

void	display_player(t_data *data)
{
	int	size;
	int	x;
	int	y;

	size = 10;
	x = 0;
	data->img_player.img = mlx_new_image(data->mlx, size, size);
	data->img_player.addr = mlx_get_data_addr(data->img_player.img, &data->img_player.bits_per_pixel, &data->img_player.line_length, &data->img_player.endian);
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			my_mlx_pixel_put(&data->img_player, x, y, 0x0000FF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->player.p_x, data->player.p_y);
}

void	display_minimap(t_data *data)
{
	int x;
	int y;

	data->img_minimap.img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->img_minimap.addr = mlx_get_data_addr(data->img_minimap.img, &data->img_minimap.bits_per_pixel, &data->img_minimap.line_length, &data->img_minimap.endian);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->player.p_x = x * data->width_square + 20;
				data->player.p_y = y * data->height_square + 20;
				data->player.orientation = data->map[y][x];
			}
			if (data->map[y][x] == 'C')
				display_compass(data);
			if (data->map[y][x] == '1')
				display_tiles(data, x, y, 0xFFFFFF);
			if (data->map[y][x] != '1' && data->map[y][x] != 'C')
				display_tiles(data, x, y, 0xA9A9A9);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_minimap.img, 0, 0);
}
