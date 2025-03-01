/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:42:54 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 17:24:19 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handling_keys(int keycode, t_person *per)
{
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
		ft_free_map(per);
		mlx_destroy_image(per->mlx, per->img);
		mlx_destroy_window(per->mlx, per->window);
		exit(0);
	}
	return (0);
}

int	close_window(t_person *per)
{
	ft_free_map(per);
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
		per.mlx = mlx_init();
		if (!per.mlx)
			failed_init();
		per.window = mlx_new_window(per.mlx, per.win_w * 50,
				per.win_h * 50, "SO_LONG");
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
