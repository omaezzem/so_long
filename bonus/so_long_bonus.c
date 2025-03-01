/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:42:54 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 17:31:45 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_person *per)
{
	int	i;

	i = 0;
	while (per->map[i])
	{
		free(per->map[i]);
		i++;
	}
	free(per->map);
	mlx_destroy_image(per->mlx, per->img);
	mlx_destroy_window((per)->mlx, (per)->window);
	exit(0);
	return (0);
}

void	init_person(t_person *per)
{
	per->collect = 0;
	per->movement = 0;
	per->win_h = len_h((*per).map);
	per->win_w = ft_strlen((*per).map[0]);
	per->x_person = ft_x_person(per->map);
	per->y_person = ft_y_person(per->map);
	per->enemy_count = 0;
}

void	parsing(t_person *per)
{
	check_map_size(per);
	check_map(per);
	ckeck_collectables(per);
}

int	main(int ac, char **av)
{
	t_person	per;

	if (ac <= 1)
		invalid_n_arg();
	check_file_ber(av[1]);
	per.map = lines_map(av[1]);
	if (per.map != NULL)
	{
		parsing(&per);
		init_person(&per);
		init_window(&per);
		setup_hooks(&per);
	}
	cleanup(&per);
	return (0);
}
