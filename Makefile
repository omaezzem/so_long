# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 11:54:40 by omaezzem          #+#    #+#              #
#    Updated: 2025/02/17 15:51:27 by omaezzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror 


SRCS 	=	mandatory/so_long.c\
			mandatory/utils/utilis.c\
			mandatory/utils/ft_strlcpy.c\
			mandatory/utils/len_h.c\
			mandatory/utils/split.c\
			mandatory/src/get_lines.c\
			mandatory/src/xpm_to_img.c\
			mandatory/src/mouvements.c\
			mandatory/src/mvm_utilis.c\
			mandatory/src/scan2.c\
			mandatory/src/errors.c\
 			mandatory/src/walls.c\
			mandatory/src/check_file.c\
			mandatory/src/scan_map.c\
			mandatory/src/add_to_map.c\
			mandatory/src/img.c\
			mandatory/gnl/get_next_line.c\
			mandatory/gnl/get_next_line_utils.c\

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all