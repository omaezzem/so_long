/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:06:39 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 17:27:38 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_image(t_person **per, int x, int y, char *img)
{
	int	w;
	int	h;

	if (!per || !*per)
		return ;
	(*per)->img = mlx_xpm_file_to_image((*per)->mlx, img, &w, &h);
	if (!(*per)->img)
	{
		write(2, "Error\nFailed to load image\n", 28);
		ft_error_free(&per);
		exit(1);
		return ;
	}
	mlx_put_image_to_window((*per)->mlx, (*per)->window, (*per)->img, x, y);
}

void	put_image_enemy(t_person **per, int x, int y, char *img)
{
	int	w;
	int	h;

	if (!per || !*per)
		return ;
	(*per)->enemy->img = mlx_xpm_file_to_image((*per)->mlx, img, &w, &h);
	if (!(*per)->enemy->img)
	{
		write(2, "Error\nFailed to load image\n", 28);
		ft_free_map(*per);
		exit(1);
		return ;
	}
	mlx_put_image_to_window((*per)->mlx, (*per)->window,
		(*per)->enemy->img, x, y);
}

void	render_enemies(t_person *per)
{
	int	i;

	i = 0;
	while (i < per->enemy_count)
	{
		put_image_enemy(&per, per->enemy[i].x_enemy, per->enemy[i].y_enemy,
			"./bonus/xmp_bonus/e1.xpm");
		i++;
	}
}

void	enemy_to_map(t_person **per, int x, int y)
{
	int	i;

	i = (*per)->enemy_count;
	if (i < MAX_ENEMIES)
	{
		(*per)->enemy[i].x_enemy = x;
		(*per)->enemy[i].y_enemy = y;
		(*per)->enemy_count++;
	}
}

void	image_to_map(char p, int x, int y, t_person **per)
{
	if (p == '1')
		put_image(per, x, y, "./bonus/xmp_bonus/wall.xpm");
	else if (p == 'C')
	{
		put_image(per, x, y, "./bonus/xmp_bonus/money.xpm");
		(*per)->collect++;
	}
	else if (p == 'P')
	{
		(*per)->x_person = x;
		(*per)->y_person = y;
		put_image(per, x, y, "./bonus/xmp_bonus/right.xpm");
	}
	else if (p == '0')
		put_image(per, x, y, "./bonus/xmp_bonus/floor.xpm");
	else if (p == 'E')
		put_image(per, x, y, "./bonus/xmp_bonus/close.xpm");
	else if (p == 'W')
		enemy_to_map(per, x, y);
	else
	{
		ft_putstr_fd("Error\ninvalid elements\n", 2);
		exit(1);
	}
}
