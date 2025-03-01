/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:34:33 by omaezzem          #+#    #+#             */
/*   Updated: 2025/02/28 17:34:34 by omaezzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include "gnl_bonus/get_next_line.h"

# define MAX_ENEMIES 10

typedef struct s_enemy
{
	void	*img;
	int		x_enemy;
	int		y_enemy;
}	t_enemy;

typedef struct s_person
{
	void	*mlx;
	void	*img;
	void	*window;
	int		win_w;
	int		win_h;
	int		x_person;
	int		y_person;
	int		movement;
	int		collect;
	char	**map;
	int		enemy_count;
	t_enemy	enemy[MAX_ENEMIES];
}	t_person;

char	**ft_split(char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		len_h(char **line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_itoa(int n);

char	**lines_map(char *file);
void	check_file_ber(char *f_ber);
void	check_map(t_person *per);
void	is_rectangular(t_person **per);
void	check_between_walls(t_person **mapw);
int		last_h_lines(char **hight, int h);
int		first_h_lines(char **h);
int		last_w_lines(char **line, int w);
int		first_w_lines(char **line);

void	add_to_map(t_person *per);
void	image_to_map(char p, int x, int y, t_person **per);
void	exit_the_door(t_person ***per);
void	ft_right(t_person **per);
void	ft_left(t_person **per);
void	ft_up(t_person **per);
void	ft_down(t_person **per);
void	collected(t_person ***per);
void	id_upp_down(t_person **per, int id);
void	id_left_right(t_person **per, int id);
void	tfloor(t_person **per);
bool	flood_fill_exit(char **map, int x, int y, t_person *per);
int		flood_fill_collect(char **map, int x, int y, t_person *per);
char	**copy(char **map, int width, int height);
void	init_person(t_person *per);
void	ft_error_free(t_person ***fmap);
void	failed_init(void);
void	invalid_map(void);
void	failed_w(void);
void	invalid_n_arg(void);
void	check_if_newline(t_person *per);

int		n_ex(t_person *per);
int		n_pl(t_person *per);
int		n_co(t_person *per);
int		n_enemy(t_person *per);
void	invalid_by_walls(void);
void	render_enemies(t_person *per);
void	invalid_rectangle(void);

void	ft_free_map(t_person *fmap);
void	free_memory(char **map);
void	free_map(char **map, int height);
int		ft_x_person(char **map);
int		ft_y_person(char **map);
void	ckeck_collectables(t_person *per);
int		ft_y_enemy(char **map);
int		ft_x_enemy(char **map);
void	check_enemy(t_person *per);
void	put_text(t_person ***per);

char	*ft_str_join(char *s1, char *s2);
int		animate(t_person *per);
void	check_map_size(t_person *per);
int		handling_keys(int keycode, t_person *per);
int		close_window(t_person *per);
void	cleanup(t_person *per);
void	setup_hooks(t_person *per);
void	init_window(t_person *per);
void	is_e_p_c(t_person *per);

#endif
