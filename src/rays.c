#include "../include/cub3D.h"

void init_ray(t_data *data)
{
	data->ray.r_angle = data->angle_player;
	printf("ray angle = %f\n", data->ray.r_angle);
	// look_up;
	if (fabs(data->ray.r_angle) < 3.14)
	{
		data->ray.r_y = (int)(data->y_player / (WIDTH / 10)) * (WIDTH / 10) + -0.0001;
		data->ray.r_x = data->x_player - (data->y_player - data->ray.r_y) * 1 / (tan(data->ray.r_angle));
	}
	if (fabs(data->ray.r_angle) > 3.14)
	{
		data->ray.r_y = (int)(data->y_player / (WIDTH / 10)) * (WIDTH / 10) + (WIDTH / 10);
		data->ray.r_x = data->x_player - (data->y_player - data->ray.r_y) * 1 / (tan(data->ray.r_angle));
	}
	if (data->angle_player == 0)
	{
		data->ray.r_y = data->y_player;
		data->ray.r_x = data->x_player;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_dot.img, (int)data->ray.r_x, (int)data->ray.r_y);
}