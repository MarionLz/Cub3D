/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:32:41 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:42 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_floor_ceiling_format(char **colors, t_data *data, char *line)
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
			{
				free_tab(colors);
				error_textures(data, "colors components must be 3 digits set between\
 0 and 255, separated by a ',' without space", line);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		free_tab(colors);
		error_textures(data, "colors components must be 3 digits set between 0 and 255,\
 separated by a ',' without space", line);
	}
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
	if (data->p_count < 4)
		data->p_count += 1;
	*dir += 1;
	check_counts(data, line);
	data->texture[i].path = get_path(&line[3]);
	if (!data->texture[i].path)
		error_textures(data, "a path to texture's file must be provided\n",
			line);
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
