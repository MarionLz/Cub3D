#include "../include/cub3D.h"

int	display_error(char *error_msg)
{
	printf("Error\n%s\n", error_msg);
	exit(1);
}

void	error_map(t_data *data, char *error_msg)
{
	close(data->fd);
	free_tab(data->map);
	free_mlx(data);
	free_paths(data);
	display_error(error_msg);
}

void	error_file(t_data *data, char *line, char *error_msg)
{
	close(data->fd);
	free_mlx(data);
	free(line);
	display_error(error_msg);
}

void	error_textures(t_data *data, char *error_msg, char *line)
{
	free_mlx(data);
	free_paths(data);
	free(line);
	close(data->fd);
	free(data->stash);
	display_error(error_msg);
}

void	error_no_map(t_data *data, char *error_msg)
{
	free_mlx(data);
	free_paths(data);
	display_error(error_msg);
}
