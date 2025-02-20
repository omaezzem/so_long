/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_person_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:39:42 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 21:47:08 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int		ft_x_person(char **map)
{
	int i = 0;
	int x = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				x = j;
			j++;
		}
		i++;
	}
	return x;
}

int		ft_y_person(char **map)
{
	int i = 0;
	int x = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				x = i;
			j++;
		}
		i++;
	}
	return x;
}
