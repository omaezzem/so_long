/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:32:01 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 17:12:24 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		first_w_lines(char **line)
{
	int i = 0;
	while (line[0][i] != '\0')
	{
		if (line[0][i] != '1')
			return 0;
		i++;
	}
	return 1;
}
int		last_w_lines(char **line, int w)
{
	int i = 0;
	while (line[w][i] != '\0')
	{
		if (line[w][i] != '1')
			return 0;
		i++;
	}
	return 1;
}

void	ft_error_free(t_person ***fmap)
{
	int	x;
	x = 0;
	while ((**fmap)->map[x])
	{
		free((**fmap)->map[x]);
		x++;
	}
	free((**fmap)->map);
	ft_putstr_fd(RED "🛑ERROR: map is not surrounded by walls", 2);
	exit(1);
}

int		first_h_lines(char **h)
{
	int i = 0;
	while (h[i] != NULL)
	{
		if (h[i][0] != '1')
			return 0;
		i++;
	}
	return 1;
}

int		last_h_lines(char **hight, int h)
{
	int i = 0;
	while (hight[i] != NULL)
	{
		if (hight[i][h] != '1')
			return 0;
		i++;
	}
	return 1;
}
