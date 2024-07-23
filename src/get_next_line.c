/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:32:06 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:07 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*clean_stash(t_data *data, unsigned int i)
{
	char			*tmp;
	unsigned int	j;
	unsigned int	len_tmp;

	len_tmp = ft_strlen(data->stash) - i;
	tmp = (char *)malloc((len_tmp + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (data->stash[i])
		tmp[j++] = data->stash[i++];
	tmp[j] = '\0';
	free(data->stash);
	return (tmp);
}

static unsigned int	my_str_chr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*fill_line(t_data *data, unsigned int *i)
{
	unsigned int	j;
	char			*line;

	*i = my_str_chr(data->stash, '\n');
	if (*i == 0)
		*i = ft_strlen(data->stash);
	j = 0;
	line = (char *)malloc((*i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < *i)
	{
		line[j] = data->stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_text(t_data *data, int fd)
{
	char	*buffer;
	char	*tmp;
	int		nb_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (nb_read != 0 && !ft_strchr(data->stash, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == 0 && ft_strlen(data->stash))
			break ;
		else if (nb_read == 0 || nb_read == -1)
		{
			free(buffer);
			free(data->stash);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		tmp = data->stash;
		data->stash = ft_strjoin_and_free(tmp, buffer);
	}
	free(buffer);
	return (data->stash);
}

char	*get_next_line(int fd, t_data *data)
{
	char			*line;
	unsigned int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	data->stash = read_text(data, fd);
	if (!data->stash)
		return (NULL);
	line = fill_line(data, &i);
	if (!line)
		return (NULL);
	data->stash = clean_stash(data, i);
	return (line);
}
