/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:39 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 17:38:17 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void put_image(t_person ***per, int x, int y, char *img)
{
    int w;
    int h;

    if (!per || !*per || !**per)
        return;
    (**per)->map = mlx_xpm_file_to_image((**per)->mlx, img, &w, &h);
    if (!(**per)->map)
    {
        write(2, "Error: Failed to load image\n", 28);
        return;
    }
    mlx_put_image_to_window((**per)->mlx, (**per)->window, (**per)->map, x, y);
}

void    image_to_map(char p, int x, int y, t_person **per)
{
    if (p == '1')
    {
        // put_image(&per, x, y, "./xpm/wall.xpm");
    }
    else if (p == 'C')
    {
        put_image(&per, x, y, "./xpm/money.xpm");
        (*per)->collect++;
    }
    else if (p == 'P')
    {
        put_image(&per, x, y, "./xpm/person2.xpm");
    }
}