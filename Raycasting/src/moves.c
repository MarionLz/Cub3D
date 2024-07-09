#include "../include/cub3D.h"

/*void	update_compass(t_data *data)
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
}*/

void	rotate(t_data *data, int direction)
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
	init_ray(data);
}

void    move_forward_back(t_data *data, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.p_x + floorf(data->player.p_speed * cos(data->player.p_angle))* dir;
    new_y = data->player.p_y + floorf(data->player.p_speed * sin(data->player.p_angle))* dir;
	if (data->map[new_y / data->height_square][(new_x - SCR_WIDTH) / data->width_square] != 1)
	{
		data->player.p_x = new_x;
		data->player.p_y = new_y;
	}
	init_ray(data);
}

void	move_left_right(t_data *data, int dir)
{
	int	new_x;
	int	new_y;
	new_x = data->player.p_x + floorf(data->player.p_speed * cos(data->player.p_angle + dir * P2));
    new_y = data->player.p_y + floorf(data->player.p_speed * sin(data->player.p_angle + dir * P2));
	if (data->map[new_y / data->height_square][(new_x - SCR_WIDTH) / data->width_square] != 1)
	{
		data->player.p_x = new_x;
		data->player.p_y = new_y;
	}
	init_ray(data);
}
