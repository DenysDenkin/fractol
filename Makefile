# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 21:12:41 by akorunsk          #+#    #+#              #
#    Updated: 2018/03/30 19:28:35 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBNAME = libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SRC = main.c \
      keyboard.c \
      mouse.c \
      init.c \
      output.c \
      fractals.c \
      fractals2.c

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc -o2 -o3 $(FLAGS) $^ -o $(NAME) -lmlx -framework AppKit -framework OpenGL

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
