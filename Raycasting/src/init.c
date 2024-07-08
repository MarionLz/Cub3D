#include "../include/cub3D.h"

void	init_data(t_data *data)
{
	data->width = 1900;
	data->height = 1000;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "WELCOME TO CUB3D");
	if (!data->win)
	{
		free(data->mlx);
		//return (1);
	}
	data->nb_colomn = 10;
	data->nb_rows = 10;
	data->width_square = data->width / data->nb_colomn;
	data->height_square = data->height / data->nb_rows;
	data->player.p_x = 390;
	data->player.p_y = 510;
	data->player.p_speed = 10;
	data->player.p_angle = 0;
	data->player.fov_rad = (FOV * PI / 180);
	data->delta_angle = 0.1;
}
