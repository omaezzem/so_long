/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:05:13 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 21:49:55 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void free_map(char **map, int height)
{
	int i;

	i = 0;
	if (!map)
		return;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free(t_person **fmap)
{
	int	x;
	x = 0;
	while ((*fmap)->map[x])
	{
		free((*fmap)->map[x]);
		x++;
	}
	free((*fmap)->map);
	exit(1);
}

void	ft_free_map(t_person *fmap)
{
	int	x;
	x = 0;
	while ((fmap)->map[x])
	{
		free((fmap)->map[x]);
		x++;
	}
	free((fmap)->map);
	exit(1);
}

void free_memory(char **map)
{
	int i;

	i = 0;
	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}