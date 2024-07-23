/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:29:25 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:37:41 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// 0 = NO ; 1 = SO; 2 = WE ; 3 = EA
void	parse_textures(char *line, t_data *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		load_path(data, line, 0, &data->no);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		load_path(data, line, 1, &data->so);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		load_path(data, line, 2, &data->we);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		load_path(data, line, 3, &data->ea);
	else
	{
		free(line);
		free_mlx(data);
		display_error("path must be separated of the direction with a space");
	}
}

void	convert_color(t_data *data, char **colors, char *line, int flag)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		free(line);
		free_mlx(data);
		display_error("colors components must be 3 digits set between 0 and 255,\
 separated by a ',' without space");
	}
	if (flag == 0)
	{
		data->floor_color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		data->f_count += 1;
	}
	else if (flag == 1)
	{
		data->ceiling_color = ((r & 0xff) << 16) + ((g & 0xff) << 8)
			+ (b & 0xff);
		data->c_count += 1;
	}
	check_counts(data, line);
}

void	parse_floor_ceiling(char *line, t_data *data)
{
	char	**colors;
	int		i;

	i = 0;
	while ((line[i] == 'C' || line[i] == 'F' || line[i] == ' ') && line[i])
		i++;
	colors = ft_split(&line[i], ',');
	check_floor_ceiling_format(colors, data, line);
	if (ft_strncmp(line, "F", 1) == 0)
		convert_color(data, colors, line, 0);
	else if (ft_strncmp(line, "C", 1) == 0)
		convert_color(data, colors, line, 1);
	free_tab(colors);
}

int	parse_blocs(char *line, t_data *data, int file_blocs)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO ", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA ", 2) == 0)
	{
		parse_textures(line, data);
		file_blocs++;
	}
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		parse_floor_ceiling(line, data);
		file_blocs++;
	}
	else if (is_map(line) == 1)
	{
		if (file_blocs < 6)
			error_textures(data, "please make sure to provide 4 valid paths for each\
 direction, a color for the floor and the ceiling, and to put the map at the end\
 of the file", line);
		parse_map(line, data);
		return (file_blocs += 1);
	}
	return (file_blocs);
}

void	parse_file(char **av, t_data *data)
{
	char	*line;
	int		file_blocs;

	file_blocs = 0;
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
	{
		free_mlx(data);
		free(data->stash);
		display_error("File : failed to open file.");
	}
	while (1)
	{
		line = get_next_line(data->fd, data);
		if (!line)
			break ;
		file_blocs = parse_blocs(line, data, file_blocs);
		if (file_blocs > 6)
			break ;
		free(line);
	}
	close(data->fd);
	if (file_blocs < 7)
		error_no_map(data, "File : no map found.");
}
