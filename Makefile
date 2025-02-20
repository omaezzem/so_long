NAME  	= so_long

NAME_BONUS = so_long_bonus

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror 

SRCS 	= mandatory/so_long.c\
		  mandatory/utils/utilis.c\
		  mandatory/utils/ft_strlcpy.c\
		  mandatory/utils/len_h.c\
		  mandatory/utils/split.c\
		  mandatory/src/get_lines.c\
		  mandatory/src/free_memory.c\
		  mandatory/src/xpm_to_img.c\
		  mandatory/src/mouvements.c\
		  mandatory/src/mvm_utilis.c\
		  mandatory/src/x_y_person.c\
		  mandatory/src/scan2.c\
		  mandatory/src/errors.c\
		  mandatory/src/errors2.c\
		  mandatory/src/n_elements.c\
		  mandatory/src/check_walls.c\
		  mandatory/src/check_file.c\
		  mandatory/src/scan_map.c\
		  mandatory/src/add_to_map.c\
		  mandatory/src/img.c\
		  mandatory/gnl/get_next_line.c\
		  mandatory/gnl/get_next_line_utils.c

BSRC = bonus/so_long_bonus.c\
		 bonus/utils_bonus/utilis.c\
		 bonus/utils_bonus/ft_strlcpy.c\
		 bonus/utils_bonus/len_h.c\
		 bonus/utils_bonus/split.c\
		 bonus/src_bonus/get_lines_bonus.c\
		 bonus/src_bonus/free_memory_bonus.c\
		 bonus/src_bonus/xpm_to_img_bonus.c\
		 bonus/src_bonus/mouvements_bonus.c\
		 bonus/src_bonus/mvm_utilis_bonus.c\
		 bonus/src_bonus/x_y_person_bonus.c\
		 bonus/src_bonus/scan2_bonus.c\
		 bonus/src_bonus/errors_bonus.c\
		 bonus/src_bonus/errors2_bonus.c\
		 bonus/src_bonus/n_elements_bonus.c\
		 bonus/src_bonus/check_walls_bonus.c\
		 bonus/src_bonus/check_file_bonus.c\
		 bonus/src_bonus/scan_map_bonus.c\
		 bonus/src_bonus/add_to_map_bonus.c\
		 bonus/src_bonus/img_bonus.c\
		 bonus/gnl_bonus/get_next_line.c\
		 bonus/gnl_bonus/get_next_line_utils.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)
BOBJS   = $(BSRC:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(BOBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all
