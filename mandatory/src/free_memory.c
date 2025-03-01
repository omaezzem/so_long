/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:05:13 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/27 17:21:28 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	fmap = NULL;
}

void	free_memory(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
