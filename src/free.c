/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:31:56 by malauzie          #+#    #+#             */
/*   Updated: 2024/07/23 14:31:58 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_paths(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_count)
	{
		free(data->texture[i].path);
		i++;
	}
	return ;
}

void	free_all(t_data *data)
{
	free_tab(data->map);
	free_paths(data);
	mlx_destroy_image(data->mlx, data->img_screen.img);
	free_mlx(data);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return ;
}
