/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:51:21 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 17:12:21 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_rectangular(t_person **per)
{
	int i = 1;
	while ((*per)->map[i] != NULL)
	{
		if (ft_strlen((*per)->map[0]) != ft_strlen((*per)->map[i]))
		{
			ft_putstr_fd(RED "Error : maps must be rectangular\n", 2);
			exit(1);
		}
		i++;
	}
}

void	check_between_walls(t_person **mapw)
{
	int h;
	int w;

	h = len_h((*mapw)->map) - 1;
	w = ft_strlen((*mapw)->map[0]) - 1;
	if (!first_w_lines((*mapw)->map))
		ft_error_free(&mapw);
	else if (!first_h_lines((*mapw)->map))
		ft_error_free(&mapw);
	else if (!last_w_lines((*mapw)->map, h))
		ft_error_free(&mapw);
	else if (!last_h_lines((*mapw)->map, w))
		ft_error_free(&mapw);
}

void	check_map(t_person *per)
{
	is_rectangular(&per);
	check_between_walls(&per);
}
