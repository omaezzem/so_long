/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:10:22 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:52:06 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_text(t_person ***per)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**per)->movement);
	text = ft_str_join("Number-> ", number);
	(**per)->img = mlx_xpm_file_to_image(
			(**per)->mlx, "./bonus/xmp_bonus/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**per)->mlx, (**per)->window, (**per)->img, 0, 0);
	mlx_put_image_to_window(
		(**per)->mlx, (**per)->window, (**per)->img, 50, 0);
	mlx_put_image_to_window(
		(**per)->mlx, (**per)->window, (**per)->img, 50 * 2, 0);
	mlx_string_put((**per)->mlx, (**per)->window, 5, 10, 0xfffffff, text);
	ft_putstr_fd(number, 1);
	ft_putchar_fd('\n', 1);
	free(text);
	free(number);
}
