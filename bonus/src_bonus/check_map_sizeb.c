/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sizeb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:28:23 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 18:05:38 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_map_size(t_person *per)
{
	int	h;
	int	w;

	h = len_h(per->map);
	w = ft_strlen(per->map[0]);
	if (h > 40)
	{
		free_map(per->map, h);
		invalid_map();
	}
	else if (w > 159)
	{
		free_map(per->map, h);
		invalid_map();
	}
}
