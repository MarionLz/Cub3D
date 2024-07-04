#include "../include/cub3D.h"

void init_ray(t_data *data)
{
	int		map_x;
	int		map_y;
	bool	hit_wall;

	data->ray.r_angle = data->player.p_angle;
	if (data->ray.r_angle < PI)
	{
		data->ray.r_y = (int)(data->player.p_y / data->height_square) * data->height_square + data->height_square;
		data->ray.r_x = (data->ray.r_y - data->player.p_y) / tan(data->ray.r_angle) + data->player.p_x;
		data->ray.r_yinter += data->height_square;
	}
	else if (data->ray.r_angle > PI)
	{
		data->ray.r_y = (int)(data->player.p_y / data->height_square) * data->height_square;
		data->ray.r_x = (data->ray.r_y - data->player.p_y) / tan(data->ray.r_angle) + data->player.p_x;
		data->ray.r_yinter -= data->height_square;
	}
	if (data->ray.r_angle == 0 || data->ray.r_angle == PI)
	{
		data->ray.r_y = data->player.p_y;
		data->ray.r_x = data->player.p_x;
	}
	hit_wall = false;
	if (hit_wall == false)
	{
		map_x = data->ray.r_x / data->width_square;
		if (data->ray.r_angle > PI)
			map_y = data->ray.r_y / data->height_square - 1;
		else
			map_y = data->ray.r_y / data->height_square;
		if (data->map[map_y][map_x] == 1)
		{
			hit_wall = true;
			printf("WALL\n");
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_dot.img, (int)data->ray.r_x, (int)data->ray.r_y);
}
