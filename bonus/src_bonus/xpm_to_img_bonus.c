/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:11:17 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:24:00 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	id_left_right(t_person **per, int id)
{
	int	w_img;
	int	h_img;

	if (id == 1)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./bonus/xmp_bonus/right.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
	else if (id == 2)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./bonus/xmp_bonus/left.xpm", &w_img, &h_img);
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
				"./bonus/xmp_bonus/upp.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
	else if (id == 2)
	{
		(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
				"./bonus/xmp_bonus/down.xpm", &w_img, &h_img);
		mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
			(*per)->x_person, (*per)->y_person);
	}
}

void	tfloor(t_person **per)
{
	int	w_img;
	int	h_img;

	(*per)->img = mlx_xpm_file_to_image((*per)->mlx,
			"./bonus/xmp_bonus/floor.xpm", &w_img, &h_img);
	mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img,
		(*per)->x_person, (*per)->y_person);
}
