#include "../include/cub3D.h"

void	update_compass(t_data *data)
{
	double	x;
	double	y;

	put_pixel(data->img_compass, data->width_square, data->height_square, 0x000000);
	x = (data->width_square / 2) * -1;
	while (x < data->width_square / 2)
	{
		y = (data->height_square / 2) * -1;
		while (y < data->height_square / 2)
		{
			if (y == floorf(tan(data->player.p_angle) * x))
				my_mlx_pixel_put(&data->img_compass, (x + data->width_square / 2), (y + data->height_square / 2), 0x00FF0000);
			y += 1;
		}
		x += 1;
	}
}

void	rotate_player(t_data *data, int dir)
{
	if (dir == 1)
	{
		data->player.p_angle += data->delta_angle;
		if (data->player.p_angle > (2 * PI))
			data->player.p_angle -= (2 * PI);
	}
	if (dir == -1)
	{
		data->player.p_angle -= data->delta_angle;
		if (data->player.p_angle < 0)
			data->player.p_angle += (2 * PI);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, GAME_WIDTH, 0);
	update_compass(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, GAME_WIDTH, 0);
	init_ray(data);
}

void    move_forward_back(t_data *data, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.p_x + floorf(data->player.p_speed * cos(data->player.p_angle))* dir;
    new_y = data->player.p_y + floorf(data->player.p_speed * sin(data->player.p_angle))* dir;
	if (data->map[new_y / data->height_square][(new_x - GAME_WIDTH) / data->width_square] != 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, data->player.p_x, data->player.p_y);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, new_x, new_y);
		data->player.p_x = new_x;
		data->player.p_y = new_y;
	}
}

void	move_left_right(t_data *data, int dir)
{
	int	new_x;
	int	new_y;
	new_x = data->player.p_x + floorf(data->player.p_speed * cos(data->player.p_angle + dir * P2));
    new_y = data->player.p_y + floorf(data->player.p_speed * sin(data->player.p_angle + dir * P2));
	if (data->map[new_y / data->height_square][(new_x - GAME_WIDTH) / data->width_square] != 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, data->player.p_x, data->player.p_y);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, new_x, new_y);
		data->player.p_x = new_x;
		data->player.p_y = new_y;
	}
}
