#include "../include/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT, "WELCOME TO CUB3D");
	if (!data->win)
	{
		free(data->mlx);
		//return (1);
	}
	data->nb_colomn = 10;
	data->nb_rows = 10;
	data->width_square = MAP_WIDTH / data->nb_colomn;
	data->height_square = SCR_HEIGHT / data->nb_rows;
	data->player.p_x = 3 * data->width_square + data->width_square / 2 + GAME_WIDTH;
	data->player.p_y = data->height_square + data->height_square / 2;
	data->player.p_speed = 10;
	data->player.p_angle = 0;
	data->player.fov_rad = (FOV * PI / 180);
	data->delta_angle = 0.1;
}
