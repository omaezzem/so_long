/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_person.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:39:42 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/25 23:35:42 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_x_person(char **map)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				x = j;
			j++;
		}
		i++;
	}
	return (x);
}

int	ft_y_person(char **map)
{
	int	i;
	int	y;
	int	j;

	i = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				y = i;
			j++;
		}
		i++;
	}
	return (y);
}
