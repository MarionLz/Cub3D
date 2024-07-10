#include "../include/cub3D.h"

int	get_texture(t_data *data)
{
	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	if (data->ray.flag == 0)
	{
		if (data->ray.r_angle > PI / 2 && data->ray.r_angle < 3 * (PI / 2))
			return (2);
		else
			return (3);
	}
	else
	{
		if (data->ray.r_angle > 0 && data->ray.r_angle < PI)
			return (1);
		else
			return (0);
	}
}

void	get_text_x(t_data *data, int text_nb)
{
	if (data->ray.flag == 1)
	{
		data->text_x = fmodf(data->ray.horiz_x, data->texture[text_nb].height);
		if (text_nb == 1)
			data->text_x = data->texture[text_nb].height - data->text_x;
	}
	else
	{
		data->text_x = fmodf(data->ray.horiz_y, data->texture[text_nb].height);
		if (text_nb == 2)
			data->text_x = data->texture[text_nb].height - data->text_x;
	}
}

void	draw_wall(t_data *data, int top_pix, int bottom_pix, int ray)
{
	int		text_nb;
	double	step;

	text_nb = get_texture(data);
	step = data->texture[text_nb].height / data->wall_height;
	data->text_y = (top_pix - SCR_HEIGHT / 2 + data->wall_height / 2) * step;
	get_text_x(data, text_nb);
	while (top_pix < bottom_pix)
	{
		data->color = data->wall[text_nb][data->texture[text_nb].height * data->text_y
			+ data->text_x];
		data->text_y += step;
		my_mlx_pixel_put(&data->img_screen, ray, top_pix, 0x00FF0000);
		top_pix++;
	}
}

void	draw_floor_and_ceiling(t_data *data, int ray, int bottom_pix, int top_pix)
{
	int	i;

	i = bottom_pix;
	while (i < SCR_HEIGHT)
	{
		my_mlx_pixel_put(&data->img_screen, ray, i, 0x0000FF00);
		i++;
	}
	i = 0;
	while (i < top_pix)
	{
		my_mlx_pixel_put(&data->img_screen, ray, i, 0x000000FF);
		i++;
	}
}

void	display_wall(t_data *data, int ray)
{
	int		bottom_pix;
	int		top_pix;

	//correction effet fisheye
	data->ray.r_distance *= cos(normalize_angle(data->ray.r_angle - data->player.p_angle));

	//calcul hauteur en pixel du mur a afficher
	data->wall_height = (SQUARE_SIZE / data->ray.r_distance) *
				((SCR_WIDTH / 2) / tan(data->player.fov_rad / 2));

	//calcul de la position du top pixel et du bottom pixel
	bottom_pix = (SCR_HEIGHT / 2) + (data->wall_height / 2);
	top_pix = (SCR_HEIGHT /2) - (data->wall_height / 2);

	if (bottom_pix > SCR_HEIGHT)
		bottom_pix = SCR_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(data, top_pix, bottom_pix, ray);
	draw_floor_and_ceiling(data, ray, bottom_pix, top_pix);
}
