/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:52:10 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/27 16:54:31 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_rectangle(void)
{
	ft_putstr_fd("Error\n🛑 maps must be rectangular\n", 2);
	exit(1);
}
