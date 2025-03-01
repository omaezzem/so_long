/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:51:21 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 00:05:22 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_rectangular(t_person **per)
{
	int	i;
	int	h;

	i = 0;
	h = len_h((*per)->map);
	while ((*per)->map[i] != NULL)
	{
		if (ft_strlen((*per)->map[0]) != ft_strlen((*per)->map[i]))
		{
			free_map((*per)->map, h);
			invalid_rectangle();
		}
		i++;
	}
}

void	check_between_walls(t_person **mapw)
{
	int	h;
	int	w;

	h = len_h((*mapw)->map) - 1;
	w = ft_strlen((*mapw)->map[0]) - 1;
	if (!first_w_lines((*mapw)->map))
	{
		ft_error_free(&mapw);
		invalid_by_walls();
	}
	else if (!first_h_lines((*mapw)->map))
	{
		ft_error_free(&mapw);
		invalid_by_walls();
	}
	else if (!last_w_lines((*mapw)->map, h))
	{
		ft_error_free(&mapw);
		invalid_by_walls();
	}
	else if (!last_h_lines((*mapw)->map, w))
	{
		ft_error_free(&mapw);
		invalid_by_walls();
	}
}

void	check_map(t_person *per)
{
	int		x;
	int		y;
	char	**map;

	is_rectangular(&per);
	check_between_walls(&per);
	is_e_p_c(per);
	x = ft_x_person(per->map);
	y = ft_y_person(per->map);
	map = copy((per)->map, per->win_w, per->win_h);
	if ((flood_fill_exit(map, x, y, per)) == false)
	{
		free_map(per->map, per->win_h);
		free_memory(map);
		invalid_map();
	}
	free_memory(map);
}

void	len_like_co(t_person *per, int w_h, char **map)
{
	int		org_len;
	int		len_c;
	int		x;
	int		y;

	org_len = n_co(per);
	x = ft_x_person(per->map);
	y = ft_y_person(per->map);
	len_c = flood_fill_collect(map, x, y, per);
	if (org_len != len_c)
	{
		free_map(per->map, w_h);
		free_memory(map);
		invalid_map();
	}
}

void	ckeck_collectables(t_person *per)
{
	char	**map;
	int		w_h;
	int		w_w;

	w_h = len_h(per->map);
	w_w = ft_strlen(per->map[0]);
	map = copy(per->map, w_w, w_h);
	w_h = len_h(per->map);
	len_like_co(per, w_h, map);
	free_memory(map);
}
