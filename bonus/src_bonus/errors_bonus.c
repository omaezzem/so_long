/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:16:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 21:17:33 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	invalid_map(void)
{
	ft_putstr_fd("Error\nERROR🛑:Invalid map\n", 2);
	exit(1);
}

void	failed_init(void)
{
	ft_putstr_fd("Error\nERROR🛑: Failed to initialize MLX\n", 2);
	exit(1);
}

void	failed_w(void)
{
	ft_putstr_fd("Error\nERROR🛑: Failed to create window\n", 2);
	exit(1);
}

void	invalid_n_arg(void)
{
	ft_putstr_fd("Error\nERROR🛑: Invalid number of arguments.\n", 2);
	exit(1);
}

void	invalid_by_walls(void)
{
	ft_putstr_fd("Error\n🛑ERROR: map is not surrounded by walls\n", 2);
	exit(1);
}
