#include "../include/cub3D.h"

void	draw_wall(t_data *data, int top_pix, int bottom_pix, int ray)
{
	//trace un trait du top_pix au bottom_pix
	while (top_pix < bottom_pix)
	{
		mlx_pixel_put(data->mlx, data->win, ray, top_pix, 0x00FF0000);
		top_pix++;
	}
}

void	display_wall(t_data *data, int ray)
{
	double	wall_height;
	int		bottom_pix;
	int		top_pix;

	//correction effet fisheye
	data->ray.r_distance *= cos(data->ray.r_angle - data->player.p_angle);

	//calcul hauteur en pixel du mur a afficher
	wall_height = (data->height_square / data->ray.r_distance) *
				((MAP_WIDTH / 2) / tan(data->player.fov_rad / 2));

	//calcul de la position du top pixel et du bottom pixel
	bottom_pix = (SCR_HEIGHT / 2) + (wall_height / 2);
	top_pix = (SCR_HEIGHT /2) - (wall_height / 2);

	if (bottom_pix > SCR_HEIGHT)
		bottom_pix = SCR_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;

	draw_wall(data, top_pix, bottom_pix, ray);
	//draw_floor(data, top_pix, bottom_pix);
}