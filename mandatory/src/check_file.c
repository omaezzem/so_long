/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:05:31 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 18:27:21 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_file_ber(char *f_ber)
{
    int len = ft_strlen(f_ber);

    if (len < 4 || ft_strcmp(&f_ber[len - 4], ".ber") != 0) 
    {
        ft_putstr_fd( "Error: File name must end with .ber\n", 2);
        exit(1);
    }
}