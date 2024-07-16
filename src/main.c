#include "../include/cub3D.h"

int	check_arguments(int ac, char **av)
{
	char	*file_extension;

	if (ac < 2)
		display_error("File of type '.cub' is required.");
	if (ac > 2)
		display_error("A single .cub file is required.");
	file_extension = ft_strrchr(av[1], '.');
	if (ft_strncmp(file_extension, ".cub", 4) != 0 || ft_strlen(file_extension) != ft_strlen(".cub"))
		display_error("Correct file extension is .cub.");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_arguments(ac, av);
	parse_file(av, &data);
	//init_data(&data);
	//init_textures(&data);
	//printf("%ls\n", data.texture[0].addr);
	//create_images(&data);
	//print_map(&data);
	//init_ray(&data);
	//mlx_hook(data.win, 02, 1L<<0, &key_press, &data); //key_press : move the player
	//mlx_hook(data.win, 03, 1L<<1, &key_release, 0); //key_release : close the window with ESC
	//mlx_hook(data.win, 17, 0, &close_win, &data); // close the window with the red cross
	//mlx_loop(data.mlx);
}
