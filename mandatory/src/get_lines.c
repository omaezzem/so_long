/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:50:47 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/19 15:39:01 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_er(void)
{
	ft_putstr_fd(RED "ERROR\n", 1);
	exit(1);
}

char	**lines_map(char *file)
{
	char	*line;
	char	*all_lines;
	int		fd;
	char	**split_map;

	line = "";
	all_lines = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_er();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_er();
	split_map = ft_split(all_lines, '\n');
	return (split_map);
}
