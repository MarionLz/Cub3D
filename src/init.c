#include "../include/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "WELCOME TO MOLKY MUSEUM, a unique exhibition of a magnificient cat portraits !");
	if (!data->win)
	{
		free(data->mlx);
		//return (1);
	}
	data->x_player = WIDTH/10*5;
	data->y_player = HEIGHT/10*5;
	data->speed_player = 10;
	data->angle_player = 0;
	data->delta_angle = 0.1;
}
