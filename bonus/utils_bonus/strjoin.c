/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:09:42 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:05 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_str_join(char *s1, char *s2)
{
	char	*concatenate;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	concatenate = malloc(len + 1);
	if (!concatenate)
		return (NULL);
	ft_strlcpy(concatenate, s1, len + 1);
	ft_strlcat(concatenate, s2, len + 1);
	return (concatenate);
}
