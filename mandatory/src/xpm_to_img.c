/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:11:17 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/25 23:35:18 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	id_left_right(t_person **per, int id)
{
	int	w_img;
	int	h_img;

	if (id == 1)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./mandatory/xmp/right.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
	else if (id == 2)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./mandatory/xmp/left.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
}

void	id_upp_down(t_person **per, int id)
{
	int	w_img;
	int	h_img;

	if (id == 1)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./mandatory/xmp/upp.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
	else if (id == 2)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./mandatory/xmp/down.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
}

void	tfloor(t_person **per)
{
	int	w_img;
	int	h_img;

	(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
			"./mandatory/xmp/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
		(*per)->x_person, (*per)->y_person);
}
