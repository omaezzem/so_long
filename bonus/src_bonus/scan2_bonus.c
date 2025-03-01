/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:28:35 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/27 16:34:29 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	is_e_p_c(t_person *per)
{
	int	e;
	int	p;
	int	c;
	int	w;

	e = n_ex(per);
	p = n_pl(per);
	c = n_co(per);
	w = n_enemy(per);
	if (e != 1)
		invalid_map();
	if (p != 1)
		invalid_map();
	if (c < 1)
		invalid_map();
	if (w > MAX_ENEMIES)
		invalid_map();
}

char	**copy(char **map, int width, int height)
{
	char	**cpy_map;
	int		i;
	int		j;

	i = 0;
	cpy_map = malloc(sizeof(char *) * (height + 1));
	if (!cpy_map)
		return (NULL);
	while (i < height)
	{
		cpy_map[i] = malloc(sizeof(char) * (width + 1));
		if (!cpy_map[i])
			return (NULL);
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

bool	flood_fill_exit(char **map, int x, int y, t_person *per)
{
	bool	reached;

	reached = false;
	if (x <= 0 || y <= 0 || x >= per->win_w || y >= per->win_h
		|| map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'W')
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

int	flood_fill_collect(char **map, int x, int y, t_person *per)
{
	int	w_h;
	int	w_w;
	int	i;

	w_h = len_h(per->map);
	i = 0;
	w_w = ft_strlen(per->map[0]);
	if (x <= 0 || y <= 0 || x >= w_w || y >= w_h
		|| map[y][x] == 'E' || map[y][x] == 'X' || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		i = 1;
	map[y][x] = 'X';
	i += flood_fill_collect(map, x + 1, y, per);
	i += flood_fill_collect(map, x - 1, y, per);
	i += flood_fill_collect(map, x, y + 1, per);
	i += flood_fill_collect(map, x, y - 1, per);
	return (i);
}

bool	flood_fill_enemy(char **map, int x, int y, t_person *per)
{
	bool	found;

	if (x <= 0 || y <= 0 || x >= per->win_w || y >= per->win_h)
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (false);
	if (map[y][x] == 'W')
		return (true);
	map[y][x] = 'X';
	found = flood_fill_enemy(map, x + 1, y, per)
		|| flood_fill_enemy(map, x - 1, y, per)
		|| flood_fill_enemy(map, x, y + 1, per)
		|| flood_fill_enemy(map, x, y - 1, per);
	return (found);
}
