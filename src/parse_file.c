# include "../include/cub3D.h"

// 0 = NO ; 1 = SO; 2 = WE ; 3 = EA
void	parse_textures(char *line, t_data *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		data->texture[0].path = get_path(&line[3]);
		//printf("%s\n", data->texture[0].path);
		if (!data->texture[0].path)
			display_error("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		data->texture[1].path = get_path(&line[3]);
		//printf("%s\n", data->texture[1].path);
		if (!data->texture[1].path)
			display_error("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		data->texture[2].path = get_path(&line[3]);
		//printf("%s\n", data->texture[2].path);
		if (!data->texture[2].path)
			display_error("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		data->texture[3].path = get_path(&line[3]);
		//printf("%s\n", data->texture[3].path);
		if (!data->texture[3].path)
			display_error("a path to texture's file must be provided\n");
	}
}


void	parse_floor_and_ceiling(char *line, t_data *data)
{
	char	**colors;
	int		i;
	int		r;
	int		g;
	int		b;
	unsigned long tmp;

	i = 0; 
	while((line[i] == 'C' || line[i] == 'F' || line[i] == ' ') && line[i])
		i++;
	colors = ft_split(&line[i], ',');
	check_floor_ceiling_format(colors);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		display_error("3colors components must be 3 digits set between 0 and 255, separated by a ','");
	if (ft_strncmp(line, "F", 1) == 0)
	{
		tmp = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		data->floor_color = tmp;
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		tmp = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		data->ceiling_color = tmp;
	}
	printf("floor color : %lx\n", data->floor_color);
	printf("ceiling color : %lx\n", data->ceiling_color);
	free_tab(colors);
}

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
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
	{
		parse_textures(line, data);
		file_blocs++;
	}
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		parse_floor_and_ceiling(line, data);
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
		if (file_blocs > 6)
			break;
		free(line);
	}
	close(data->fd);
	if (file_blocs < 3)
		display_error("File : no map found.");
}
