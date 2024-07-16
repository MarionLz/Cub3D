# include "../include/cub3D.h"

// 0 = NO ; 1 = SO; 2 = WE ; 3 = EA
void	parse_textures(char *line, t_data *data)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		data->texture[0].path = ft_strdup(&line[3]);
		if (!data->texture[0].path)
			ft_error("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		data->texture[1].path = ft_strdup(&line[3]);
		if (!data->texture[1].path)
			perror("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		data->texture[2].path = ft_strdup(&line[3]);
		if (!data->texture[2].path)
			perror("a path to texture's file must be provided\n");
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		data->texture[3].path = ft_strdup(&line[3]);
		if (!data->texture[3].path)
			perror("a path to texture's file must be provided\n");
	}
}

void	check_floor_ceiling_format(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0' || !line)
		ft_error("colors components must be 3 digits set between 0 and 255, separated by a ','");
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			ft_error("colors components must be 3 digits set between 0 and 255, separated by a ','");
		i++;
	}
}

void	parse_floor_and_ceiling(char *line, t_data *data)
{
	char	**colors;
	int		i;
	int		r;
	int		g;
	int		b;

	i = 0;
	check_floor_ceiling_format(&line[2]);
	colors = ft_split(&line[2], ',');
	while (colors[i])
		i++;
	if (i > 2)
		ft_error("colors components must be 3 digits set between 0 and 255, separated by a ','");
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 && r > 255 || g < 0 && g > 255 || b < 0 && b > 255)
		ft_error("colors components must be 3 digits set between 0 and 255, separated by a ','");
	if (ft_strncmp(line, "F", 1) == 0)
		data->floor_color = rgb_to_hexadecimal(r, g, b);
	else if (ft_strncmp(line, "C", 1) == 0)
		data->ceiling_color = rgb_to_hexadecimal(r, g, b);
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
