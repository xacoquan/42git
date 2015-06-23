










#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/30 19:29:54 by xacoquan          #+#    #+#              #
#    Updated: 2015/06/06 11:55:58 by xacoquan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = game_2048

SRC = 	check_arg.c		\
		check_move.c	\
		del_game.c		\
		error.c			\
		ft_tool.c		\
		grid.c			\
		init_game.c		\
		main.c			\
		menu.c			\
		move.c			\
		move_number.c	\
		over.c			\
		print.c			\
		pseudo.c		\
		restart.c		\
		score.c			\
		stat.c


OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) -I ./libft/includes -I . -c $(SRC)
	gcc $(FLAGS) -lncurses  $(OBJ) -L ./libft -lft -o $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
