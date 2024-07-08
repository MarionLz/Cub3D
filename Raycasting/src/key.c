#include "../include/cub3D.h"

int	key_press(int keycode, t_data *data)
{
	//rotate left
    if (keycode == ROTATE_LEFT)
        rotate_player(data, 1);
    //rotate right
	if (keycode == ROTATE_RIGHT)
        rotate_player(data, -1);
    //forward
	if (keycode == FORWARD)
        move_player(data, 1);
	//back
    if (keycode == BACK)
        move_player(data, -1);
    return (0);
}

int	key_release(int keycode)
{
	// esc
    if (keycode == 65307)
        close_win();
    return (0);
}