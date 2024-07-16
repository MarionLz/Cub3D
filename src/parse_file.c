# include "../include/cub3D.h"

int	is_map(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i] == ' ')
		i++;
	if (ft_strchr("01NSEW", str[i]))
		return (1);
	return (0);
}

int	parse_blocs(char *line, t_data *data, int file_blocs)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		//parse_textures(line);
		file_blocs++;
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		//parse_floor(line);
		file_blocs++;
	}
	else if (is_map(line) == 1)
	{
		if (file_blocs < 2)
			error_file(data, line, "File : map description must be at the end of the file.");
		parse_map(line, data);
		return (file_blocs += 1);
	}
	return (file_blocs);
}

void	parse_file(char **av, t_data *data)
{
	char *line;
	int	file_blocs;

	file_blocs = 0;
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		display_error("File : failed to open file.");
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		file_blocs = parse_blocs(line, data, file_blocs);
		if (file_blocs == 3)
			break;
		free(line);
	}
	close(data->fd);
	if (file_blocs < 3)
		display_error("File : no map found.");
}
