#include "../include/cub3D.h"

void	update_minimap(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_minimap.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img_compass.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img_player.img, data->player.p_x, data->player.p_y);
}

void	init_ray(t_data *data)
{
	double	h_distance;
	double	v_distance;
	int		ray;

	ray = 0;
	data->ray.r_angle = data->player.p_angle - (data->player.fov_rad / 2);
	printf("ray angle before norm = %f\n", data->ray.r_angle);	
	printf("player angle = %f\n", data->player.p_angle);
	printf("ray angle after norm = %f\n", data->ray.r_angle);
	update_minimap(data);
	while (ray < SCR_WIDTH)
	{
		h_distance = get_horizontal_distance(data);
		v_distance = get_vertical_distance(data);
		if (h_distance <= v_distance || data->ray.vert_dir == 1)
		{
			data->ray.r_distance = h_distance;
			mlx_put_image_to_window(data->mlx, data->win, data->img_doth.img, (int)data->ray.horiz_x, (int)data->ray.horiz_y);
		}
		else if (v_distance < h_distance || data->ray.horiz_dir == 1)
		{
			data->ray.r_distance = v_distance;
			mlx_put_image_to_window(data->mlx, data->win, data->img_dotv.img, (int)data->ray.vert_x, (int)data->ray.vert_y);
		}
		ray++;
		data->ray.r_angle += data->player.fov_rad / SCR_WIDTH;
		printf("ray angle = %f\n", data->ray.r_angle);
		//printf("ray angle = %f\n", data->player.fov_rad / SCR_WIDTH);
	}
}

double normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

int		hit_wall(t_data *data, double x, double y, char flag)
{
	int	map_x;
	int	map_y;
	
	map_x = (x) / data->width_square; //wWrning : Xavier a ecrit ici !
	//printf("mapx = %d\n", map_x);
	//printf("x = %f\n", x);
	//printf("cos = %f\n", cos(data->ray.r_angle));
	//printf("sin = %f\n", sin(data->ray.r_angle));
	if (flag == 'V' && data->ray.r_angle > P2 && data->ray.r_angle < P3)
		map_x = (x) / data->width_square - 1;
	map_y = (y) / data->height_square;
	if (flag == 'H' && data->ray.r_angle > PI) 
		map_y = (y) / data->height_square - 1;
	if (map_x < 0 || map_y < 0 || map_x >= data->nb_colomn || map_y >= data->nb_rows)
		return (0);
	if (data->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

double	get_horizontal_distance(t_data *data)
{
	double h_x = 0;
	double h_y = 0;
	double inter_x = 0;
	double inter_y = 0;

	data->ray.horiz_dir = 0;
	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	//if (data->ray.r_angle == 0 || data->ray.r_angle == PI)
		//return (data->ray.horiz_dir = 1);
	if (data->ray.r_angle < PI)
	{
		h_y = floor(data->player.p_y / data->height_square) * data->height_square + data->height_square;
		h_x = (h_y - data->player.p_y) / tan(data->ray.r_angle) + data->player.p_x;
		inter_y = data->height_square;
		inter_x = inter_y / tan(data->ray.r_angle);
	}
	else if (data->ray.r_angle > PI)
	{
		h_y = floor(data->player.p_y / data->height_square) * data->height_square;
		h_x = (h_y - data->player.p_y) / tan(data->ray.r_angle) + data->player.p_x;
		inter_y = -data->height_square;
		inter_x = inter_y / tan(data->ray.r_angle);
	}
	if ((data->ray.r_angle > P2 && data->ray.r_angle < P3 && inter_x > 0) || ((data->ray.r_angle > P3 || data->ray.r_angle < P2) && inter_x < 0))
		inter_x *= -1;
	//mlx_put_image_to_window(data->mlx, data->win, data->img_doth.img, h_x, h_y);
	while (hit_wall(data, h_x, h_y, 'H') == 1)
	{
		h_x += inter_x;
		h_y += inter_y;
		//mlx_put_image_to_window(data->mlx, data->win, data->img_doth.img, h_x, h_y);
	}
	data->ray.horiz_x = h_x;
	data->ray.horiz_y = h_y;
	//mlx_put_image_to_window(data->mlx, data->win, data->img_doth.img, h_x, h_y);
	return (sqrt(pow(h_x - data->player.p_x, 2) + pow(h_y - data->player.p_y, 2)));
}

double	get_vertical_distance(t_data *data)
{
	double v_x = 0;
	double v_y = 0;
	double inter_x = 0;
	double inter_y = 0;

	data->ray.vert_dir = 0;
	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	//if (data->ray.r_angle == P2 || data->ray.r_angle == P3)
		//return (data->ray.vert_dir = 1);
	// look left
	if (data->ray.r_angle > P2 && data->ray.r_angle <= P3)
	{
		v_x = (data->player.p_x / data->width_square) * data->width_square;
		v_y = (v_x - data->player.p_x) * tan(data->ray.r_angle) + data->player.p_y;
		inter_x = -data->width_square;
		inter_y = inter_x * tan(data->ray.r_angle);
	}
	// look right
	if (data->ray.r_angle <= P2 || data->ray.r_angle > P3)
	{
		v_x = (data->player.p_x / data->width_square) * data->width_square + data->width_square;
		v_y = (v_x - data->player.p_x) * tan(data->ray.r_angle) + data->player.p_y;
		inter_x = data->width_square;
		inter_y = inter_x * tan(data->ray.r_angle);
	}
	if ((data->ray.r_angle > 0 && data->ray.r_angle < PI && inter_y < 0) || (data->ray.r_angle > PI && data->ray.r_angle < 2*PI && inter_y > 0))
		inter_y *= -1;
	while (hit_wall(data, v_x, v_y, 'V') == 1)
	{
		v_x += inter_x;
		v_y += inter_y;
		//mlx_put_image_to_window(data->mlx, data->win, data->img_dotv.img, v_x, v_y);
	}
	data->ray.vert_x = v_x;
	data->ray.vert_y = v_y;
	//mlx_put_image_to_window(data->mlx, data->win, data->img_dotv.img, v_x, v_y);
	return (sqrt(pow(v_x - data->player.p_x, 2) + pow(v_y - data->player.p_y, 2)));
}
