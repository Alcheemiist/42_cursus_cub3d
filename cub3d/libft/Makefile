# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefilee                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 04:12:21 by eelaazmi          #+#    #+#              #
#    Updated: 2019/10/25 02:34:34 by eelaazmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_strdup.c ft_isalnum.c ft_strlcpy.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_tolower.c ft_strlcat.c\
	  ft_itoa.c ft_putchar_fd.c ft_memset.c ft_memmove.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_isprint.c \
	  ft_putendl_fd.c  ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c  ft_strncmp.c \
	  ft_strjoin.c ft_strlen.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c\
	  ft_strnstr.c ft_split.c ft_strrchr.c ft_strtrim.c ft_toupper.c \

OBJT = ft_atoi.o ft_bzero.o ft_strdup.o ft_isalnum.o ft_strlcpy.o \
	  ft_isalpha.o ft_isascii.o ft_isdigit.o ft_tolower.o ft_strlcat.o\
	  ft_itoa.o ft_putchar_fd.o ft_memset.o ft_memmove.o \
	  ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_isprint.o \
	  ft_putendl_fd.o  ft_putnbr_fd.o ft_putstr_fd.o ft_strchr.o  ft_strncmp.o \
	  ft_strjoin.o ft_strlen.o ft_strmapi.o ft_substr.o ft_calloc.o ft_isprint.o\
	  ft_strnstr.o ft_split.o ft_strrchr.o ft_strtrim.o ft_toupper.o \

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar -rc $(NAME) $(OBJT)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus :
