/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/15 14:26:54 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void ft_right(t_person **per, int number)
{
    int w_img, h_img;
    int new_x = (*per)->x_person + 50;
    char next_tile = (*per)->map[(*per)->y_person / 50][new_x / 50];

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);

    if (next_tile == 'E' && (*per)->collect <= 0)
        exit_the_dore(&per);
    else if (next_tile != '1')
    {
        ft_putnbr_fd(number, 1);
        (*per)->x_person = new_x;
        number++;
        if (next_tile == 'C')
            collected(&per);
    }

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/right.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}


void ft_left(t_person **per, int number)
{
    int w_img, h_img;
    int new_x = (*per)->x_person - 50;
    char next_tile = (*per)->map[(*per)->y_person / 50][new_x / 50];

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);

    if (next_tile == 'E' && (*per)->collect <= 0)
        exit_the_dore(&per);
    else if (next_tile != '1')
    {
        ft_putnbr_fd(number, 1);
        (*per)->x_person = new_x;
        number++;
        if (next_tile == 'C')
            collected(&per);
    }

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/left.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}


void ft_upp(t_person **per, int number)
{
    int w_img, h_img;
    int new_y = (*per)->y_person - 50;
    char next_tile = (*per)->map[new_y / 50][(*per)->x_person / 50];

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);

    if (next_tile == 'E' && (*per)->collect <= 0)
    {
        exit_the_dore(&per);
    }
    else if (next_tile != '1')
    {
        (*per)->y_person = new_y;
        ft_putnbr_fd(number, 1);
        number++;
        if (next_tile == 'C')
            collected(&per);
    }

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/upp.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}

void ft_down(t_person **per, int number)
{
    int w_img, h_img;
    int new_y = (*per)->y_person + 50;
    char next_tile = (*per)->map[new_y / 50][(*per)->x_person / 50];

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/floor.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);

    if (next_tile == 'E' && (*per)->collect <= 0)
        exit_the_dore(&per);
    else if (next_tile != '1')
    {
        (*per)->y_person = new_y;
        ft_putnbr_fd(number, 1);
        number++;
        if (next_tile == 'C')
            collected(&per);
    }

    (*per)->img = mlx_xpm_file_to_image((*per)->mlx, "./mandatory/xmp/face.xpm", &w_img, &h_img);
    mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, (*per)->x_person, (*per)->y_person);
}
