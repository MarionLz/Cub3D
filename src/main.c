#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	int	map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	printf("map = %d\n", map[0][0]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 10*64, 10*64, "WELCOME TO MOLKY MUSEUM, a unique exhibition of a magnificient cat portraits !");
	if (!win)
	{
		free(mlx);
		return (1);
	}
	mlx_loop(mlx);
}
