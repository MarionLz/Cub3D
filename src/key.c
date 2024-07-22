#include "../include/cub3D.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ROTATE_LEFT)
		rotate(data, 1);
	if (keycode == ROTATE_RIGHT)
		rotate(data, -1);
	if (keycode == FORWARD)
		move_forward_back(data, 1);
	if (keycode == BACK)
		move_forward_back(data, -1);
	if (keycode == LEFT)
		move_left_right(data, -1);
	if (keycode == RIGHT)
		move_left_right(data, 1);
    return (0);
}

int	key_release(int keycode, t_data *data)
{
	// esc
	if (keycode == 65307)
		close_win(data);
	return (0);
}

int    close_win(t_data *data)
{
	free_all(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	return (1);
}