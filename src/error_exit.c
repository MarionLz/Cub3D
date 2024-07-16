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
	free_map(data->map);
	exit(1);
}

void	error_file(t_data *data, char *line, char *error_msg)
{
	display_error(error_msg);
	close(data->fd);
	free(line);
	exit(1);
}

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int    close_win(void)
{
	exit (0);
	return (1);
}