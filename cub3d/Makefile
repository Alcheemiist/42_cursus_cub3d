# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 17:05:03 by eelaazmi          #+#    #+#              #
#    Updated: 2020/11/24 17:05:09 by eelaazmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

SRC = files/check.c files/check_two.c files/dprojection.c files/dprojection_two.c\
	  files/drawing_functions.c files/drawing_functions_two.c files/errors.c\
	  files/main.c files/main_casting_two.c files/main_casting.c files/main_read_mapandpaths.c\
	  files/main_read_mapandpaths_two.c files/main_read_mapandpaths_three.c files/main_read_mapandpaths_four.c\
	  files/main_read_mapandpaths_five.c files/main_two.c files/other_functions_utils.c files/player_functions.c\
	  files/technical_functions.c files/texture_functions.c files/texture_functions_two.c ./scrennshot/save.c\
	
OBJECT = files/check.o files/check_two.o files/dprojection.o files/dprojection_two.o\
	  files/drawing_functions.o files/drawing_functions_two.o files/errors.o\
	  files/main.o files/main_casting_two.o files/main_casting.o files/main_read_mapandpaths.o\
	  files/main_read_mapandpaths_two.o files/main_read_mapandpaths_three.o files/main_read_mapandpaths_four.o\
	  files/main_read_mapandpaths_five.o files/main_two.o files/other_functions_utils.o files/player_functions.o\
	  files/technical_functions.o files/texture_functions.o files/texture_functions_two.o ./scrennshot/save.o\
	
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c\

LIBFT = libft/libft.a

FRAMEWORK = -framework OpenGL -framework AppKit -Wreturn-type\

MLX = -lmlx\

FLAGS = -Wall -Wextra -Werror\

RED=\033[0;31m\
GREEN=\033[0;32m\
NC=\033[0m\

all: $(NAME)

$(NAME):
	@echo  "\033[0;32m > compilation success \033[0m"
	gcc  $(FLAGS) $(SRC) -o $(NAME) $(GNL) $(LIBFT) $(MLX) $(FRAMEWORK)
	
clean:
	@echo  "\033[0;31m > CLEAN OBJECTS \033[0m" 
	rm -f $(OBJECT)
	
fclean: clean
	@echo  "\033[0;31m > CLEAN ALL \0033[0m"
	rm -f $(NAME)
	rm -f cub3D
	rm -f screenshot.bmp
re: fclean all
