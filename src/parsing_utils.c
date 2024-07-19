#include "../include/cub3D.h"

void	check_floor_ceiling_format(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]) && colors[i][j] != '\n')
				display_error("colors components must be 3 digits set between\
 0 and 255, separated by a ',' without space");
			j++;
		}
		i++;
	}
	if (i != 3)
		display_error("colors components must be 3 digits set between 0 and 255,\
 separated by a ',' without space");
}

char	*get_path(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	i = 0;
	while (s[i] == ' ')
		i++;
	len = 0;
	while (s[i + len] && s[i + len] != ' ' && s[i + len] != '\n')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}

void	load_path(t_data *data, char *line, int i, int *dir)
{
	data->texture[i].path = get_path(&line[3]);
	*dir += 1;
	if (!data->texture[i].path)
		display_error("a path to texture's file must be provided\n");
}

void	init_p_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.p_angle = P3;
	if (dir == 'S')
		data->player.p_angle = P2;
	if (dir == 'E')
		data->player.p_angle = 0;
	if (dir == 'W')
		data->player.p_angle = PI;
}

int	init_player(t_data *data, int x, int y, int count_player)
{
	if (count_player > 0)
		error_map(data, "Map : more than 1 player have been found.");
	data->player.map_x = x;
	data->player.map_y = y;
	data->player.p_x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_speed = 10;
	data->player.fov_rad = (FOV * PI / 180);
	init_p_angle(data, data->map[y][x]);
	return (1);
}