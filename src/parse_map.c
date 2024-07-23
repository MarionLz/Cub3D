/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:32:36 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:54:20 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 1)
		return (true);
	while (line[i] == ' ')
		i++;
	if (i == (int)ft_strlen(line) - 1)
		return (true);
	return (false);
}

bool	closed_map(t_data *data, int x, int y)
{
	if (x == 0 || y == 0)
		return (false);
	if (y == data->nb_rows - 1 || x == ((int)ft_strlen(data->map[y]) - 1))
		return (false);
	if (data->map[y][x - 1] == ' ' || data->map[y][x + 1] == ' ')
		return (false);
	if (data->map[y - 1][x] == ' ' || data->map[y + 1][x] == ' ')
		return (false);
	if (data->map[y - 1][x - 1] == ' ' || data->map[y + 1][x - 1] == ' ')
		return (false);
	if (data->map[y - 1][x + 1] == ' ' || data->map[y + 1][x + 1] == ' ')
		return (false);
	return (true);
}

void	check_map(t_data *data)
{
	int	x;
	int	y;
	int	count_player;

	y = 0;
	count_player = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!ft_strchr("01NSEW ", data->map[y][x]))
				error_map(data, "Map : invalid character detected. Allowed characters\
		 are : 01NSEW and space.");
			if (data->map[y][x] == '0' && closed_map(data, x, y) == false)
				error_map(data, "Map : map is not closed.");
			if (ft_strchr("NSEW", data->map[y][x]))
				count_player = init_player(data, x, y, count_player);
			x++;
		}
		y++;
	}
	if (count_player == 0)
		error_map(data, "Map : no player found.");
}

void	parse_map(char *line, t_data *data)
{
	char	*map_str;

	map_str = ft_strdup(line);
	data->nb_rows++;
	free(line);
	while (1)
	{
		line = get_next_line(data->fd, data);
		if (!line)
			break ;
		if (empty_line(line) == true)
		{
			free(map_str);
			error_textures(data, "Map : empty line", line);
		}
		map_str = ft_strjoin_and_free(map_str, line);
		free(line);
		data->nb_rows++;
	}
	data->map = ft_split(map_str, '\n');
	free(map_str);
	check_map(data);
}
