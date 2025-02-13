/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:42:54 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 17:37:35 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_person(t_person *per)
{
	per->collect = 0;
	per->movement = 0;
	per->win_h = len_h((*per).map);
	per->win_w = ft_strlen((*per).map[0]);
}

int main(int ac, char **av)
{
	t_person	per;

	if (ac <= 1)
	{
		perror(RED "Error🛑: Invalid number of arguments.\n");
		exit(1);
	}
	check_file_ber(av[1]);
	per.map = lines_map(av[1]);
	if (per.map != NULL)
	{
		check_map(&per);
		init_person(&per);
		per.mlx = mlx_init(); // init inialize the game with the graphique system 
		per.window = mlx_new_window(per.mlx, per.win_h * 200, per.win_w * 25, "SO_LONG");
		add_to_map(&per);
	}
	mlx_loop(per.mlx);
}
