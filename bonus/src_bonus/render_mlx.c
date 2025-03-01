/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:59:05 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:52:01 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_window(t_person *per)
{
	per->mlx = mlx_init();
	if (!per->mlx)
		failed_init();
	per->window = mlx_new_window(per->mlx, per->win_w * 50,
			per->win_h * 50, "SO_LONG");
	if (!per->window)
		failed_w();
}

void	setup_hooks(t_person *per)
{
	add_to_map(per);
	mlx_hook(per->window, 2, 0, handling_keys, per);
	mlx_hook(per->window, 17, 0, close_window, per);
	mlx_loop_hook(per->mlx, animate, per);
}

void	cleanup(t_person *per)
{
	mlx_loop(per->mlx);
	mlx_destroy_image(per->mlx, per->img);
	mlx_destroy_window(per->mlx, per->window);
	ft_free_map(per);
}
