/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:33:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/21 18:54:21 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


void add_bonus_map(t_person **per)
{
    int h;
    int w;

    if (!per || !(*per)) 
        return;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./bonus/xmp_bonus/floor.xpm", &w, &h);
    if (!(*per)->img)
    {
        ft_putstr_fd("Error: Failed to load image\n", 2);
        return;
    }
    mlx_put_image_to_window(
        (*per)->mlx, (*per)->window, (*per)->img,
        (*per)->enemy.x_enemy * 50, (*per)->enemy.y_enemy * 50);
    (*per)->img = mlx_xpm_file_to_image(
        (*per)->mlx, (*per)->enemy.imgs[(*per)->enemy.tmp_x],
        &w, &h);
    mlx_put_image_to_window(
        (*per)->mlx, (*per)->window, (*per)->img,
        (*per)->enemy.x_enemy * 50, (*per)->enemy.y_enemy * 50);
}

void move_e(t_person **per)
{
    int w, h;

    if (!per || !(*per))
        return;
    (*per)->img = mlx_xpm_file_to_image(
        (*per)->mlx, "./bonus/xmp_bonus/floor.xpm", &w, &h);
    if (!(*per)->img)
    {
        ft_putstr_fd("Error: Failed to load image\n", 2);
        return;
    }
    mlx_put_image_to_window(
        (*per)->mlx, (*per)->window, (*per)->img,
        (*per)->enemy.x_enemy * 50, (*per)->enemy.y_enemy * 50);

    if ((*per)->enemy.direction == 0)
    {
        if ((*per)->map[(*per)->enemy.y_enemy][(*per)->enemy.x_enemy + 1] != '1')
            (*per)->enemy.x_enemy++;
        else
            (*per)->enemy.direction = 1;
    }
    else
    {
        if ((*per)->map[(*per)->enemy.y_enemy][(*per)->enemy.x_enemy - 1] != '1')
            (*per)->enemy.x_enemy--;
        else
            (*per)->enemy.direction = 0;
    }
}


int check_is_space(t_person **per, int x, int y)
{
	if ((*per)->map[y][x] == '0' && (*per)->map[y][x + 1] == '0'
		&& (*per)->map[y][x + 2] == '0')
	{
		(*per)->enemy.direction = 0;
		(*per)->enemy.x_enemy= x;
		(*per)->enemy.y_enemy= y;
		return (1);
	}
	return (0);
}

void    ft_lose(t_person ***per)
{
    int i;

    i = 0;
    while ((**per)->map[i])
    {
        free((**per)->map[i]);
        i++;
    }
    free((**per)->map);
    ft_putstr_fd("GAME OVER -> YOU LOSE ❌", 1);
    mlx_destroy_image((**per)->mlx, (**per)->img);
    mlx_destroy_window((**per)->mlx, (**per)->window);
    exit(0);
}
int check_if_enemy(t_person **per)
{
    int x;
    int y;
    int height;

    height = len_h((*per)->map);
    if ((*per)->enemy.direction)
    {
        y = 0;
        while (y != height)
        {
            x = 0;
            while ((*per)->map[y][x] != '\0')
            {
                if ((*per)->map[y][x] == 'X')
                   add_bonus_map(per);
                x++;
            }
            y++;
        }
        return 0;
    }
    return 1;
}

void    put_open_door(t_person **per, int x, int y)
{
    int h;
    int w;

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, 
                "./bonus/xmp_bonus/openx.xpm", &w, &h);
     if (!(*per)->img)
    {
        ft_putstr_fd("Error: Failed to load door image\n", 2);
        return;
    }
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, x * 50, y * 50);
}
void    open_door(t_person **per)
{
    int x;
    int y;
    int height;

    y = 0;
    height = len_h((*per)->map);
    while (y != height)
    {
        x = 0;
        while ((*per)->map[y][x] != '\0')
        {
            if ((*per)->map[y][x] == 'E')
                put_open_door(per, x, y);
            x++;
        }
        y++;
    }
}

int animate(t_person **per)
{
    if ((*per)->enemy.sleep-- <= 0)
    {
        (*per)->enemy.tmp_x++;
        (*per)->enemy.sleep = 1;
    }
    if ((*per)->enemy.tmp_x >= 1)
        (*per)->enemy.tmp_x = 0;
    if ((*per)->enemy.speed-- <= 0)
    {
        move_e(per);
        (*per)->enemy.speed = 40;
    }
    if ((*per)->enemy.y_enemy == (*per)->y_person / 50 &&
        (*per)->enemy.x_enemy == (*per)->x_person / 50)
        ft_lose(&per);
    add_bonus_map(per);
    if ((*per)->collect <= 0)
        open_door(per);
    return 0;
}


