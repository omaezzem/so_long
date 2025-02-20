/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 17:59:25 by omaezzem         ###   ########.fr       */
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
    int next_x;
    int next_y;

    tfloor(per);
    next_x = (*per)->x_person / 50 + 1;
    next_y = (*per)->y_person / 50;
    if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
        exit_the_door(&per);
    else if ((*per)->map[next_y][next_x] != '1' && (*per)->map[next_y][next_x] != 'E')
    {
        (*per)->movement++;
        ft_counter_mouv(per);
        (*per)->x_person += 50;
    }
    if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
        collected(&per);
    id_left_right(per, 1);
}

void ft_left(t_person **per)
{
    int next_x;
    int next_y;

    tfloor(per);
    next_x = (*per)->x_person / 50 - 1;
    next_y = (*per)->y_person / 50;
    if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
        exit_the_door(&per);
    else if ((*per)->map[next_y][next_x] != '1' && (*per)->map[next_y][next_x] != 'E')
    {
        (*per)->movement++;
        ft_counter_mouv(per);
        (*per)->x_person -= 50;
    }
    if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
        collected(&per);
    id_left_right(per, 2);
}

void ft_up(t_person **per)
{
    int next_x;
    int next_y;

    tfloor(per);
    next_y = (*per)->y_person / 50 - 1;
    next_x = (*per)->x_person / 50;
    if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
        exit_the_door(&per);
    else if ((*per)->map[next_y][next_x] != '1' && (*per)->map[next_y][next_x] != 'E')
    {
        (*per)->movement++;
        (*per)->y_person -= 50;
        ft_counter_mouv(per);
    }
    if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
        collected(&per);
    id_upp_down(per, 1);
}

void ft_down(t_person **per)
{

    int next_x;
    int next_y;

    tfloor(per);
    next_y = (*per)->y_person / 50 + 1;
    next_x = (*per)->x_person / 50;
    if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
        exit_the_door(&per);
    else if ((*per)->map[next_y][next_x] != '1' && (*per)->map[next_y][next_x] != 'E')
    {
        (*per)->movement++;
        (*per)->y_person += 50;
        ft_counter_mouv(per);
    }
    if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
        collected(&per);
    id_upp_down(per, 2);
}
