/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:16:19 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/17 15:25:27 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void invalid_map(void)
{
    ft_putstr_fd("ERROR🛑:Invalid map\n", 2);
		exit(1);
}

void    failed_init(void)
{
    ft_putstr_fd("ERROR🛑: Failed to initialize MLX\n", 2);
   		exit(1);
}

void    failed_w(void)
{
    ft_putstr_fd("ERROR🛑: Failed to create window\n", 2);
    	exit(1);
}

void invalid_n_arg(void)
{
	ft_putstr_fd("ERROR🛑: Invalid number of arguments.\n", 2);
	exit(1);
}