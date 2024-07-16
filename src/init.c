#include "../include/cub3D.h"

void	init_data(t_data *data)
{
	//data->width = 1900;
	//data->height = 1000;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT, "WELCOME TO CUB3D");
	if (!data->win)
	{
		free(data->mlx);
		//return (1);
	}
	data->nb_colomn = 10;
	data->nb_rows = 10;
	//data->width_square = SCR_WIDTH / data->nb_colomn;
	//data->height_square = SCR_HEIGHT / data->nb_rows;
	data->player.p_x = 390;
	data->player.p_y = 510;
	data->player.p_speed = 10;
	data->player.p_angle = 0;
	data->player.fov_rad = (FOV * PI / 180);
	data->text_y = 0;
	data->text_x = 0;
	data->delta_angle = 0.1;
	data->ray.flag = 0;
	data->color = 0;
}

void	init_texture_data(t_data *data/*, char **argv */)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].width = TILE_SIZE;
		data->texture[i].height = TILE_SIZE;
		i++;
	}
	//extract_textures(data, argv[1]);
}

//convert the xpm file sent into a void* image that can be used by
//the program
void	*convert_img(t_data *data, char *path, int i)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &(data->texture[i].width),
			&(data->texture[i].width));
	return (img);
}

char	*get_data_address(t_texture *texture)
{
	char *address;

	address = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel),
			&(texture->line_length), &(texture->endian));
	return (address);
}

void	store_textures_pixels(t_data *data, int i)
{
	int	x;
	int	y;
	int	text_i;

	y = 0;
	while (y < data->texture[i].height)
	{
		x = 0;
		while (x < data->texture[i].width)
		{
			text_i = data->texture[i].height * y + x;
			data->wall[i][text_i] = data->texture[i].addr[text_i];
			x++;
		}
		y++;
	}
}

void	init_textures(t_data *data)
{
	int	i;

	i = 0;
	init_texture_data(data);
	while (i < 4)
	{
		data->texture[i].img = convert_img(data, data->texture[i].path, i);
		if (!data->texture[i].img)
			printf("failed to load img/n");
		data->texture[i].addr = (int *)get_data_address(&(data->texture[i]));
		if (!data->texture[i].addr)
			printf("failed to load texture address\n");
		printf("%ls\n", data->texture[i].addr);
		store_textures_pixels(data, i);
		//mlx_destroy_image(data->mlx, data->texture[i].img);
		i++;
	}
}