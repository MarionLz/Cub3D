#include "../include/cub3D.h"

void	draw_compass(t_img img, int size, int color)
{
	int	x;
	int	y;
	
	y = size / 2;
	x = size / 2;
	while (x < size)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}
}

void	put_pixel(t_img img, int size, int color)
{
	int	x;
	int	y;

	x = 1;
	while (x < size - 1)
	{
		y = 1;
		while (y < size - 1)
		{
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
  char	*dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}