/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm_utilis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:29:24 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 18:00:31 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    exit_the_door(t_person ***per)
{
    int i;

    i = 0;
    ft_putstr_fd(YLW "YOU WON 🏆", 1);
    while ((**per)->map[i])
    {
        free((**per)->map[i]);
        i++;
    }
    free((**per)->map);
    mlx_destroy_image((**per)->mlx, (**per)->img);
    exit(1);
}

void	collected(t_person ***per)
{
	int		img_w;
	int		img_h;

	(**per)->collect--;
	(**per)->map[((**per)->y_person / 50)][((**per)->x_person / 50)] = '0';
	(**per)->img = mlx_xpm_file_to_image(
			(**per)->mlx, "./mandatory/xmp/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**per)->mlx, (**per)->window, (**per)->img, (**per)->x_person, (**per)->y_person);
}
