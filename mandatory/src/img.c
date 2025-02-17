/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:39 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/17 16:13:01 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void put_image(t_person **per, int x, int y, char *img)
{
    int w;
    int h;

    if (!per || !*per)
        return;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, img, &w, &h);
    if (!(*per)->img)
    {
        write(2, "Error: Failed to load image\n", 28);
        return;
    }
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, x, y);
}

void    image_to_map(char p, int x, int y, t_person **per)
{
    if (p == '1')
        put_image(per, x, y, "./mandatory/xmp/wall.xpm");
    else if (p == 'C')
    {
        put_image(per, x, y, "./mandatory/xmp/money.xpm");
        (*per)->collect++;
    }
    else if (p == 'P')
    {
        (*per)->x_person = x;
        (*per)->y_person = y;
        put_image(per, x, y, "./mandatory/xmp/right.xpm");
    }
    else if (p == '0')
        put_image(per, x, y, "./mandatory/xmp/floor.xpm");
    else if (p == 'E')
        put_image(per, x, y, "./mandatory/xmp/close.xpm");
}
