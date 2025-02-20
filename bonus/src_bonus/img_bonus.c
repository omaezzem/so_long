/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:39 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/20 13:54:24 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void    image_to_map(char p, int x, int y, t_person **per, t_enemy **en)
{
    if (p == '1')
        put_image(per, x, y, "./bonus/xmp_bonus/wall.xpm");
    else if (p == 'C')
    {
        put_image(per, x, y, "./bonus/xmp_bonus/money.xpm");
        (*per)->collect++;
    }
    else if (p == 'P')
    {
        (*per)->x_person = x;
        (*per)->y_person = y;
        put_image(per, x, y, "./bonus/xmp_bonus/right.xpm");
    }
    else if (p == 'X')
        put_image(per, x, y, "./bonus/xmp_bonus/enemy.xpm");
    else if (p == '0')
        put_image(per, x, y, "./bonus/xmp_bonus/floor.xpm");
    else if (p == 'E')
        put_image(en, (*per)->enemy.x_enemy, (*per)->enemy.y_enemy, "./bonus/xmp_bonus/close.xpm");
}
