/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:32:46 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:33:16 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i] == ' ')
		i++;
	if (ft_strchr("01NSEW", str[i]))
		return (1);
	return (0);
}
