#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_data	data = {
		.map = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		}
	};
	init_data(&data);
	parse_map(ac, av);
	init_textures(&data);
	printf("%ls\n", data.texture[0].addr);
	//create_images(&data);
	//print_map(&data);
	init_ray(&data);
	mlx_hook(data.win, 02, 1L<<0, &key_press, &data); //key_press : move the player
	mlx_hook(data.win, 03, 1L<<1, &key_release, 0); //key_release : close the window with ESC
	mlx_hook(data.win, 17, 0, &close_win, &data); // close the window with the red cross
	mlx_loop(data.mlx);
}
