#include "../include/cub3D.h"

//prototype fonction de recuperation de la distance entre :
//l'intersection ou rayon rencontre un mur sur une ligne horrizontale,
// et la position du player.
float	get_h_inter(t_data *data)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	//x_step = distance horizontale entre les intersections horizontales successives
	//y_step = distance verticale entre les intersections horizontales successives
	y_step = data->width_square;
	x_step = data->width_square / tan(data->ray.r_angle);

	//position en y de la première intersection horizontale.
	h_y = floor(data->player.p_y / data->width_square) * data->width_square;

	//fonction pour obtenir première intersection horinzontale en fonction de l'angle 
	//et ajuster y_step si nécessaire.
	pixel = inter_check(data->ray.r_angle, &h_y, &y_step, 1);

	//calcul de la coordonnee x de la premiere intersection horizontale
	h_x = data->player.p_x + (h_y - data->player.p_y) / tan(data->ray.r_angle);

	//fonction "unit circle" d'ajustement du sens de x_step ?

	//recherche d'intersection avec un mur
	while (wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}

	//application de pythagore pour retourner la distance
	return (sqrt(pow(h_x - data->player.p_x, 2) + pow(h_y - data->player.p_y, 2)));
}

//prototype fonction raycasting
void	raycasting(t_data *data)
{
	double	v_inter;
	double	h_inter;
	int		ray;

	ray = 0;

	//calcul de l'angle de depart
	data->ray.r_angle = data->player.p_angle - (data->player.fov_rad / 2);

	//boucle pour caster chaque rayon
	while (ray < data->width)
	{
		h_inter = get_h_inter(data);
		v_inter = get_v_inter(data);

		if (v_inter <= h_inter)
			data->ray.r_distance = v_inter;
		else
			data->ray.r_distance = h_inter;

		display_wall(data);
		ray++;

		//passage au prochain angle
		data->ray.r_angle += (data->player.fov_rad / data->width);
	}
}