#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/30 19:29:54 by xacoquan          #+#    #+#              #
#    Updated: 2015/02/28 08:34:45 by xacoquan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME	= fdf

SRC		= draw.c\
		matrix.c\
		matrix_operations.c\
		parsing.c

OBJS	= $(SRC:.c=.o)
INC		= ./
FLAGS	= -Wall  -Wextra

CMP = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[35;1m• \033[0mCreating archive $@ ...\033[55G\c"
	make -C libft
	$(CMP) $(OBJS)  -o $(NAME) -O3 -I libft/includes -L libft/ -lft \
	-L /usr/X11/lib -lmlx -lXext -lX11 -g3
	@echo "\033[1;31;40m -------------- FDF .EXE MADE WITH SUCCESS ---------------\033[0m"

%.o: %.c
	$(CMP) -I. -o $@ -c $? $(FLAGS)


clean:
	@make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re
