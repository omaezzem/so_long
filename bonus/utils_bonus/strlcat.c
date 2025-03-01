/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:10:48 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:17 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	if (src)
	{
		i = 0;
		while (dst[i])
			i++;
		j = 0;
		while (src[j] && i < (dstsize - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return ((len_dst) + (len_src));
}
