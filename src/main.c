#include "../include/cub3D.h"

int	main(void)
{
	t_data	data;

	int	map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	init_data(&data);
	create_images(&data);
	print_map(&data, map);
	mlx_hook(data.win, 02, 1L<<0, &key_hook, &data); //key_release : move the player
	mlx_hook(data.win, 03, 1L<<1, &key_hook, &data); //key_press : close the window with ESC
	mlx_hook(data.win, 17, 0, &close_win, &data); // close the window with the red cross
	mlx_loop(data.mlx);
}
