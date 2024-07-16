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

unsigned int	rgb_to_hexadecimal(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}