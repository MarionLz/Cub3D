#include "../include/cub3D.h"

int	display_error(char *error_msg)
{
	printf("Error\n%s\n", error_msg);
	exit(1);
}

void	error_map(t_data *data, char *error_msg)
{
	display_error(error_msg);
	close(data->fd);
	free_tab(data->map);
	exit(1);
}

void	error_file(t_data *data, char *line, char *error_msg)
{
	display_error(error_msg);
	close(data->fd);
	free(line);
	exit(1);
}

void	check_counts(t_data *data)
{
	if (data->no > 1 || data->so > 1 || data->we > 1 || data->ea > 1)
		display_error(".cub file must have only one path per direction");
	if (data->c_count > 1 || data->f_count > 1)
		display_error(".cub file must have only one color for the floor or the ceiling");
}
