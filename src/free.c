#include "../include/cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_paths(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(data->texture[j].path);
		j++;
	}
	return ;
}

void	free_all(t_data *data)
{
	free_tab(data->map);
	free_paths(data, 4);
	mlx_destroy_image(data->mlx, data->img_screen.img);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return ;
}