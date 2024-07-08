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

void	rotate_player(t_data *data, int direction)
{
	if (direction == -1)
	{
		data->player.p_angle += data->delta_angle;
		if (data->player.p_angle > (2 * PI))
			data->player.p_angle -= (2 * PI);
	}
	if (direction == 1)
	{
		data->player.p_angle -= data->delta_angle;
		if (data->player.p_angle < 0)
			data->player.p_angle += (2 * PI);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, 0, 0);
	update_compass(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	init_ray(data);
}

void    move_player(t_data *data, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, data->player.p_x, data->player.p_y);
	data->player.p_x += floorf(data->player.p_speed * cos(data->player.p_angle))* dir;
    data->player.p_y += floorf(data->player.p_speed * sin(data->player.p_angle))* dir;
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->player.p_x, data->player.p_y);
}
