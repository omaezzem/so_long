/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:50:47 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 16:49:08 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_er(void)
{
	ft_putstr_fd("Error\nERROR\n", 1);
	exit(1);
}

char	*read_all_lines(int fd)
{
	char	*line;
	char	*all_lines;
	int		len_org;
	int		len_tmp;

	all_lines = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		len_org = ft_strlen(all_lines);
		len_tmp = ft_strlen(line);
		if (line[0] == '\n' && len_org != len_tmp)
		{
			free(line);
			free(all_lines);
			invalid_map();
		}
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (all_lines);
}

char	**lines_map(char *file)
{
	int		fd;
	char	*all_lines;
	char	**split_map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_er();
	all_lines = read_all_lines(fd);
	close(fd);
	if (all_lines[0] == '\0')
	{
		free(all_lines);
		ft_er();
	}
	split_map = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_map);
}
