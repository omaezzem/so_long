/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_elements_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:41:17 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 21:47:21 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_elements(t_person *per, char c)
{
	int	y1;
	int	x1;
	int	len;

	if (!per || !per->map || !per->map[0])
		return (-1);
	len = 0;
	y1 = 0;
	per->win_h = len_h(per->map);
	per->win_w = ft_strlen(per->map[0]);
	while (y1 < per->win_h)
	{
		x1 = 0;
		while (x1 < per->win_w)
		{
			if (per->map[y1][x1] == c)
				len++;
			x1++;
		}
		y1++;
	}
	return len;
}

int  n_ex(t_person *per)
{
	int i;
	i = check_elements(per, 'E');
	return i;
}

int n_pl(t_person *per)
{
	int i;
	i = check_elements(per, 'P');
	return i;
}

int n_co(t_person *per)
{
	int i;
	i = check_elements(per, 'C');
	return i;
}
