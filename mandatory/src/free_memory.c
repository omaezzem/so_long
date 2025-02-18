/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:05:13 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/18 22:02:26 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    free_memory(t_person **per)
{
    int i = 0;
    while ((*per)->map[i])
    {
        free((*per)->map[i]);
        i++;
    }
    free((*per)->map);
}

void free_map(char **map, int height)
{
    if (!map) return;
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);
}