/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/15 23:02:38 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void ft_counter_mouv(t_person **per)
{
        int number = 0;
 
        number += (*per)->movement;
        ft_putnbr_fd(number, 1);
        ft_putchar_fd('\n', 1);
}

void ft_right(t_person **per)
{
    int w_img;
    int h_img;
    char next_tile;
    char tile;


    (*per)->movement += 1;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
    next_tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50 + 1];
    tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50];
    if (next_tile == 'E')
    {
        if ((*per)->collect <= 0)
            exit_the_dore(&per);
    }
    else if (next_tile != '1')
    {
        (*per)->x_person += 50;
        ft_counter_mouv(per);
    }
    if (tile == 'C')
        collected(&per);
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/right.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}


void ft_left(t_person **per)
{
    int w_img;
    int h_img;
    char next_tile;
    char tile;

    (*per)->movement += 1;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
    next_tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50 - 1];
    tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50];
    if (next_tile == 'E')
    {
        if ((*per)->collect <= 0)
            exit_the_dore(&per);
    }
    else if (next_tile != '1')
    {
        (*per)->x_person -= 50;
        ft_counter_mouv(per);
    }
    if (tile == 'C')
        collected(&per);
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/left.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}

void ft_upp(t_person **per)
{
    int w_img;
    int h_img;
    char next_tile;
    char tile;

    (*per)->movement += 1;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
    next_tile = (*per)->map[(*per)->y_person / 50 - 1][(*per)->x_person / 50];
    tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50];
    if (next_tile == 'E')
    {
        if ((*per)->collect <= 0)
            exit_the_dore(&per);
    }
    else if (next_tile != '1')
    {
        (*per)->y_person -= 50;
        ft_counter_mouv(per);
    }
    if (tile == 'C')
        collected(&per);
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/upp.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}

void ft_down(t_person **per)
{
    int w_img;
    int h_img;
    char next_tile;
    char tile;

    (*per)->movement += 1;
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
    next_tile = (*per)->map[(*per)->y_person / 50 + 1][(*per)->x_person / 50];
    tile = (*per)->map[(*per)->y_person / 50][(*per)->x_person / 50];
    if (next_tile == 'E')
    {
        if ((*per)->collect <= 0)
            exit_the_dore(&per);
    }
    else if (next_tile != '1')
    {
        (*per)->y_person += 50;
        ft_counter_mouv(per);
    }
    if (tile == 'C')
        collected(&per);
    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/face.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}
