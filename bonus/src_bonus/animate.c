/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:33:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/27 17:31:31 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_lose(t_person **per)
{
	int	i;

	i = 0;
	while ((*per)->map[i])
	{
		free((*per)->map[i]);
		i++;
	}
	free((*per)->map);
	ft_putstr_fd("GAME OVER -> YOU LOSE ❌\n", 1);
	mlx_destroy_image((*per)->mlx, (*per)->img);
	mlx_destroy_window((*per)->mlx, (*per)->window);
	exit(0);
}

void	put_open_door(t_person *per, int x, int y)
{
	int	h;
	int	w;

	(per)->img = mlx_xpm_file_to_image((per)->mlx,
			"./bonus/xmp_bonus/openx.xpm", &w, &h);
	if (!(per)->img)
	{
		ft_putstr_fd("Error: Failed to load door image\n", 2);
		return ;
	}
	mlx_put_image_to_window((per)->mlx, (per)->window,
		(per)->img, x * 50, y * 50);
}

void	open_door(t_person *per)
{
	int	x;
	int	y;
	int	height;

	y = 0;
	height = len_h((per)->map);
	while (y != height)
	{
		x = 0;
		while (per->map[y][x] != '\0')
		{
			if (per->map[y][x] == 'E')
				put_open_door(per, x, y);
			x++;
		}
		y++;
	}
}

int	animate(t_person *per)
{
	int	i;

	i = 0;
	while (i < per->enemy_count)
	{
		if (((per)->enemy[i].y_enemy / 50 == (per)->y_person / 50)
			&& ((per)->enemy[i].x_enemy / 50 == (per)->x_person / 50))
		{
			ft_lose(&per);
			return (1);
		}
		i++;
	}
	if ((per)->collect <= 0)
		open_door(per);
	return (0);
}
