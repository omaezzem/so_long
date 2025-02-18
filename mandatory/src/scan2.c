/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:28:35 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/18 22:29:09 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_elements(t_person *per, char c)
{
	int	y1;
	int	x1;
	int e;


	if (!per || !per->map || !per->map[0])
		return (-1);

	e = 0;
	y1 = 0;
	per->win_h = len_h(per->map);
	per->win_w = ft_strlen(per->map[0]);

	while (y1 < per->win_h)
	{
		x1 = 0;
		while (x1 < per->win_w)
		{
			if (per->map[y1][x1] == c)
				e++;
			x1++;
		}
		y1++;
	}
	return e;
}
void	print_map(char **map)
{
	int i = 0;
	int j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int  n_ex(t_person *per)
{
	int i;
	i = check_elements(per, 'E');
	return i;
}

int n_pl(t_person *per)
{
	int i;
	i = check_elements(per, 'P');
	return i;
}

int n_co(t_person *per)
{
	int i;
	i = check_elements(per, 'C');
	return i;
}



char	**copy(char **map, int width, int height)
{
	char	**cpy_map;
	int		i;
	int		j;

	i = 0;
	cpy_map = malloc(sizeof(char *) * (height + 1));
	if (!cpy_map)
		return NULL;
	while (i < height)
	{
		cpy_map[i] = malloc(sizeof(char) * (width + 1));
		if (!cpy_map[i])
			return NULL;
		j = 0;
		while (j < width)
		{
			cpy_map[i][j] = map[i][j];
			j++;
		}
		cpy_map[i][width] = '\0';
		i++;
	}
	cpy_map[height] = NULL;
	return (cpy_map);
}

bool    flood_fill_exit(char **map, int x, int y, t_person *per)
{
    bool    reached;

	reached = false;
    if (x <= 0 || y <= 0 || x >= per->win_w || y >= per->win_h
        || map[y][x] == '1' || map[y][x] == 'X')
        return (false);
    if (map[y][x] == 'E')
        return (true);
    map[y][x] = 'X';
    reached = (flood_fill_exit(map, x + 1, y, per)
            || flood_fill_exit(map, x - 1, y, per)
            || flood_fill_exit(map, x, y + 1, per)
            || flood_fill_exit(map, x, y - 1, per));
    return (reached);
}
