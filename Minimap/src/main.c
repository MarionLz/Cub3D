#include "../include/cub3D.h"

int	main(void)
{
	t_data	data = { 
		.map = {
			{'C', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', 'E', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		}
	};
	init_data(&data);
	create_images(&data);
	//print_map(&data);
	display_minimap(&data);
	display_player(&data);
	init_ray(&data);
	mlx_hook(data.win, 02, 1L<<0, &key_press, &data); //key_press : move the player
	mlx_hook(data.win, 03, 1L<<1, &key_release, 0); //key_release : close the window with ESC
	mlx_hook(data.win, 17, 0, &close_win, &data); // close the window with the red cross
	mlx_loop(data.mlx);
}
