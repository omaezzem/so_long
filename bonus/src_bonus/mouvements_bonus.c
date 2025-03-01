/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 17:05:30 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	handling_keys(int keycode, t_person *per)
{
	if (keycode == 2 || keycode == 124)
		ft_right(&per);
	else if (keycode == 13 || keycode == 126)
		ft_up(&per);
	else if (keycode == 1 || keycode == 125)
		ft_down(&per);
	else if (keycode == 0 || keycode == 123)
		ft_left(&per);
	else if (keycode == 53)
	{
		ft_free_map(per);
		mlx_destroy_image(per->mlx, per->img);
		mlx_destroy_window(per->mlx, per->window);
		exit(0);
	}
	return (0);
}

void	ft_right(t_person **per)
{
	int	next_x;
	int	next_y;

	tfloor(per);
	next_x = (*per)->x_person / 50 + 1;
	next_y = (*per)->y_person / 50;
	if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
		exit_the_door(&per);
	else if ((*per)->map[next_y][next_x] != '1' &&
			(*per)->map[next_y][next_x] != 'E')
	{
		put_text(&per);
		(*per)->x_person += 50;
	}
	if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
		collected(&per);
	id_left_right(per, 1);
}

void	ft_left(t_person **per)
{
	int	next_x;
	int	next_y;

	tfloor(per);
	next_x = (*per)->x_person / 50 - 1;
	next_y = (*per)->y_person / 50;
	if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
		exit_the_door(&per);
	else if ((*per)->map[next_y][next_x] != '1' &&
			(*per)->map[next_y][next_x] != 'E')
	{
		put_text(&per);
		(*per)->x_person -= 50;
	}
	if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
		collected(&per);
	id_left_right(per, 2);
}

void	ft_up(t_person **per)
{
	int	next_x;
	int	next_y;

	tfloor(per);
	next_y = (*per)->y_person / 50 - 1;
	next_x = (*per)->x_person / 50;
	if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
		exit_the_door(&per);
	else if ((*per)->map[next_y][next_x] != '1' &&
			(*per)->map[next_y][next_x] != 'E')
	{
		put_text(&per);
		(*per)->y_person -= 50;
	}
	if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
		collected(&per);
	id_upp_down(per, 1);
}

void	ft_down(t_person **per)
{
	int	next_x;
	int	next_y;

	tfloor(per);
	next_y = (*per)->y_person / 50 + 1;
	next_x = (*per)->x_person / 50;
	if ((*per)->map[next_y][next_x] == 'E' && (*per)->collect <= 0)
		exit_the_door(&per);
	else if ((*per)->map[next_y][next_x] != '1' &&
			(*per)->map[next_y][next_x] != 'E')
	{
		put_text(&per);
		(*per)->y_person += 50;
	}
	if ((*per)->map[(*per)->y_person / 50][(*per)->x_person / 50] == 'C')
		collected(&per);
	id_upp_down(per, 2);
}
