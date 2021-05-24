# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 19:25:03 by eelaazmi          #+#    #+#              #
#    Updated: 2020/12/13 19:25:08 by eelaazmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = 	src/get_next_line/get_next_line.c			\
	 	src/get_next_line/get_next_line_utils.c		\
	 	src/draw.c 									\
		src/ft_save.c 								\
		src/main.c 									\
		src/quit_error.c 							\
		src/setup.c 								\
		src/utils.c 								\
		src/utils2.c 								\
		src/utils_for_sprite.c 						\
		src/ft_get_struct.c 						\
		src/ft_set_map.c 							\
		src/player.c 								\
		src/raycasting.c 							\
		src/sprite.c 								\
		src/utils1.c 								\
		src/utils3.c    

OBJS = *.o

all: $(NAME)

$(NAME): $(SRCS) 
	make -f src/libft/Makefile
	gcc -Wall -Wextra -Werror -c $(SRCS)
	gcc $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf libft.a
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
