#include "../include/cub3D.h"

int	key_hook(int keycode, t_data *data)
{
	//left
    if (keycode == 113)
        rotate_player(data, 1);
    //right
	if (keycode == 100)
        rotate_player(data, -1);
    //forward
	if (keycode == 122)
        move_player(data, 1);
	//back
    if (keycode == 115)
        move_player(data, -1);
	// ech
    if (keycode == 65307)
        close_win();
    return (0);
}

void	update_compass(t_data *data)
{
	float	x;
	float	y;

	put_pixel(data->img_compass, WIDTH / 10, 0x000000);
	x = (WIDTH / 10 / 2) * -1;
	while (x < WIDTH / 10 / 2)
		{
			y = (HEIGHT / 10 / 2) * -1;
			while (y < HEIGHT / 10 / 2)
			{
				if (y == floorf(tan(data->angle_player) * x))
					my_mlx_pixel_put(&data->img_compass, (x + HEIGHT / 10 / 2), (y + HEIGHT / 10 / 2), 0x00FF0000);
				y += 1;
			}
			x += 1;
		}
}

void	rotate_player(t_data *data, int dir)
{
	data->angle_player -= data->delta_angle * dir;
	mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, 0, 0);
	update_compass(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	init_ray(data);
}

void    move_player(t_data *data, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_background.img, data->x_player, data->y_player);
	data->x_player += floorf(data->speed_player * cos(data->angle_player))* dir;
    data->y_player += floorf(data->speed_player * sin(data->angle_player))* dir;
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->x_player, data->y_player);
}
