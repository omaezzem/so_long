/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:34:33 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/18 22:38:37 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "gnl/get_next_line.h"

# define PUR "\033[0;35m"
# define CY "\033[0;36m"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define GRAY "\033[1;30m"
# define YLW "\033[1;33m"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strcmp(char *s1, char *s2);
void	check_file_ber(char *f_ber);
char	**ft_split(char  *s, char c);
int		ft_strlcpy(char *dst, char *src,int dstsize);
char	**lines_map(char *file);
void	check_file_ber(char *f_ber);
int		len_h(char **line);

typedef struct s_enemy {
	int		x_enemy;
	int		y_enemy;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy;

typedef struct s_person
{
	void			*mlx;
	void			*img;
	void			*window;
	int				win_w;
	int				win_h;
	int				x_person;
	int				y_person;
	int				movement;
	int				collect;
	char			**map;
	t_enemy         e_vars;
}           t_person;


void	check_map(t_person *per);
void	is_rectangular(t_person **per);
void	check_between_walls(t_person **mapw);
int		last_h_lines(char **hight, int h);
int		first_h_lines(char **h);
void	ft_error_free(t_person ***fmap);
int		last_w_lines(char **line, int w);
int		first_w_lines(char **line);
void	add_to_map(t_person *per);
void    image_to_map(char p, int x, int y, t_person **per);
void    exit_the_door(t_person ***per);
void    ft_right(t_person **per);
void    ft_left(t_person **per);
void    ft_up(t_person **per);
void    ft_down(t_person **per);
void	collected(t_person ***per);
void    id_upp_down(t_person **per, int id);
void	tfloor(t_person **per);
void    id_left_right(t_person **per, int id);
void	open_door(t_person **per, int x, int y);
void	eff_door(t_person **per);
bool    flood_fill_exit(char **map, int x, int y, t_person *per);
char	**copy(char **map, int width, int height);




void	failed_init(void);
void	invalid_map(void);
void	failed_w(void);
void	invalid_n_arg(void);
int		n_ex(t_person *per);
int		n_pl(t_person *per);
int		n_co(t_person *per);

void    free_memory(t_person **per);
void    free_str(char **per);
void	free_map(char **map, int height);
int		ft_x_person(char **map);
int		ft_y_person(char **map);

#endif
