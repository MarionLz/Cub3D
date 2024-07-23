/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:32:21 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:22 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT,
			"WELCOME TO THE AWKWARD / CREEPY MUSEUM");
	if (!data->win)
	{
		free(data->mlx);
		exit (1);
	}
	data->nb_rows = 0;
	data->text_y = 0;
	data->text_x = 0;
	data->delta_angle = 0.1;
	data->ray.flag = 0;
	data->color = 0;
	data->no = 0;
	data->so = 0;
	data->we = 0;
	data->ea = 0;
	data->c_count = 0;
	data->f_count = 0;
	data->p_count = 0;
	data->stash = ft_strdup("");
}

int	check_arguments(int ac, char **av)
{
	char	*file_extension;

	if (ac < 2)
		display_error("File of type '.cub' is required.");
	if (ac > 2)
		display_error("A single .cub file is required.");
	file_extension = ft_strrchr(av[1], '.');
	if (ft_strncmp(file_extension, ".cub", 4) != 0
		|| ft_strlen(file_extension) != ft_strlen(".cub"))
		display_error("Correct file extension is .cub.");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_arguments(ac, av);
	init_data(&data);
	parse_file(av, &data);
	init_textures(&data);
	raycasting(&data);
	mlx_hook(data.win, 02, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 03, 1L << 1, &key_release, &data);
	mlx_hook(data.win, 17, 0, &close_win, &data);
	mlx_loop(data.mlx);
	free_all(&data);
}
