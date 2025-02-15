/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:05:31 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/13 18:44:07 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_file_ber(char *f_ber)
{
    int len = ft_strlen(f_ber);

    if (len < 4 || ft_strcmp(&f_ber[len - 4], ".ber") != 0) 
    {
        perror( "Error: File name must end with .ber\n");
        exit(1);
    }
}