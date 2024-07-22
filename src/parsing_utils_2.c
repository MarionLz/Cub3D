#include "../include/cub3D.h"

void	check_counts(t_data *data, char *line)
{
	if (data->no > 1 || data->so > 1 || data->we > 1 || data->ea > 1)
		error_textures(data, ".cub file must have only one path per direction",
				line);
	if (data->c_count > 1 || data->f_count > 1)
		error_textures(data, ".cub file must have only one color for the floor \
or the ceiling", line);
}