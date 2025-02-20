/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:51:21 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 21:47:16 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void is_e_p_c(t_person *per)
{
	int	e;
	int	p;
	int	c;

	e = n_ex(per);
	p = n_pl(per);
	c = n_co(per);
	if (e != 1)
		invalid_map();
	if (p != 1)
		invalid_map();
	if (c < 1)
		invalid_map();
}

void	is_rectangular(t_person **per)
{
	int	i;

	i = 0;
	while ((*per)->map[i] != NULL)
	{
		if (ft_strlen((*per)->map[0]) != ft_strlen((*per)->map[i]))
		{
			ft_error_free(&per);
			invalid_rectangle();
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
	map = copy((per)->map , per->win_w, per->win_h);
	if ((flood_fill_exit(map, x, y, per)) == false)
	{
		free_map(per->map, per->win_h);
		free_memory(map);
		invalid_map();
	}
	free_memory(map);
}

void	ckeck_collectables(t_person *per)
{
	int		org_len;
	int		i;
	int		len_c;
	char	**map;
	int		x;
	int		y;
	int		w_h;
	int		w_w;

	w_h = len_h(per->map);
	w_w = ft_strlen(per->map[0]);
	x = ft_x_person(per->map);
	y = ft_y_person(per->map);
	map = copy(per->map, w_w, w_h);
	i = 0;
	org_len = n_co(per);
	len_c = flood_fill_collect(map, x, y, per);
	w_h = len_h(per->map);
	if (org_len != len_c)
	{
		free_map(per->map, w_h);
		free_memory(map);
		invalid_map();
	}
	free_memory(map);
}
