/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:42:54 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/15 13:36:45 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	handling_keys(int keycode, t_person *per)
{
	int	x;
	int number;

	number = 0;
	if (keycode == 2 || keycode == 124)
		ft_right(&per, number);
	else if (keycode == 13 || keycode == 126)
		ft_upp(&per, number);
	else if (keycode == 1 || keycode == 125)
		ft_down(&per, number);
	else if (keycode == 0 || keycode == 123)
		ft_left(&per, number);
	else if (keycode == 53)
	{
		x = 0;
		while (per->map[x])
		{
			free(per->map[x]);
			x++;
		}
		free(per->map);
		mlx_destroy_window(per->mlx, per->window);
		exit(1);
	}
	return (0);
}

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
		per.mlx = mlx_init();
		if (!per.mlx)
		{
    		write(2, "Error: Failed to initialize MLX\n", 32);
   			exit(1);
		} 
		per.window = mlx_new_window(per.mlx, per.win_w * 50, per.win_h * 50, "SO_LONG");
		if (!per.window)
		{
    		write(2, "Error: Failed to create window\n", 32);
    		exit(1);
		}
		add_to_map(&per);
		mlx_hook(per.window, 2, 0, handling_keys, &per);
	}
	mlx_loop(per.mlx);
}
