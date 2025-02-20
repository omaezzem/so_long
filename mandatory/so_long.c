/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:42:54 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 21:16:34 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handling_keys(int keycode, t_person *per)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		ft_right(&per);
	else if (keycode == 13 || keycode == 126)
		ft_up(&per);
	else if (keycode == 1 || keycode == 125)
		ft_down(&per);
	else if (keycode == 0 || keycode == 123)
		ft_left(&per);
	else if (keycode == 53)
	{
		x = 0;
		while (per->map[x])
		{
			free(per->map[x]);
			x++;
		}
		free(per->map);
		mlx_destroy_image(per->mlx, per->img);
		mlx_destroy_window(per->mlx, per->window);
		exit(0);
	}
	return (0);
}

int close_window(t_person *per)
{
	int i;

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

void init_person(t_person *per)
{
	per->collect = 0;
	per->movement = 0;
	per->win_h = len_h((*per).map);
	per->win_w = ft_strlen((*per).map[0]);
	per->x_person = ft_x_person(per->map);
	per->y_person = ft_y_person(per->map);
}
void	f()
{
	system("leaks so_long");
}

int main(int ac, char **av)
{
	atexit(f);
	t_person	per;

	if (ac <= 1)
		invalid_n_arg();
	check_file_ber(av[1]);
	per.map = lines_map(av[1]);
	if (per.map != NULL)
	{
		init_person(&per);
		check_map(&per);
		ckeck_collectables(&per);
		per.mlx = mlx_init();
		if (!per.mlx)
			failed_init();
		per.window = mlx_new_window(per.mlx, per.win_w * 50, per.win_h * 50, "SO_LONG");
		if (!per.window)
			failed_w();
		add_to_map(&per);
		mlx_hook(per.window, 2, 0, handling_keys, &per);
		mlx_hook(per.window, 17, 0, close_window, &per);
	}
	mlx_loop(per.mlx);
	mlx_destroy_image(per.mlx, per.img);
	mlx_destroy_window(per.mlx, per.window);
	ft_free_map(&per);
}
