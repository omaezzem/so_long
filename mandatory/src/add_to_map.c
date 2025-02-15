/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:26:45 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 21:05:53 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_to_map(t_person *per)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w =	per->win_w;
	while (per->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (per->win_w > 0)
		{
			if (per->map && per->map[y_map])
                image_to_map(per->map[y_map][x_map], x1, y1, &per);
			x_map++;
			x1 += 50;
			per->win_w--;
		}
		per->win_w = backup_w;
		y_map++;
		y1 += 50;
		per->win_h--;
	}
}