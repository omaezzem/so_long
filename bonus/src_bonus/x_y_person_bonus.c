/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_person_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:39:42 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:27:09 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

int	ft_x_enemy(char **map)
{
	int	i;
	int	x;
	int	j;

	x = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W')
				x = j;
			j++;
		}
		i++;
	}
	return (x);
}

int	ft_y_enemy(char **map)
{
	int	i;
	int	x;
	int	j;

	x = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W')
				x = i;
			j++;
		}
		i++;
	}
	return (x);
}
