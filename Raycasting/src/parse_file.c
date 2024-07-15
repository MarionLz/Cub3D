# include "../include/cub3D.h"

void	parse_file(int ac, char **av)
{
	int	fd;
	char *line;

	if (ac != 2)
		perror("a single .cub file must be provided\n");
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
			parse_textures(line);
		else if (ft_strncmp(line, "F", 1) == 0)
			parse_floor(line);
		else if (is_map(line) == 1)
		{
			parse_map(line, fd);
			free(line);
			break ;
		}
		free(line);
	}
}