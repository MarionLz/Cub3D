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