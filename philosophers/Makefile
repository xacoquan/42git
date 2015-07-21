# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/07/10 14:20:31 by xacoquan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	philo
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES	=	main.c								\
			mutex.c								\
			out.c								\
			philo.c								\
			threads.c							\

INC		=	-I./includes
CCFLAGS	=	 -g -lncurses
LDFLAGS	=	-framework glut -framework Cocoa -framework OpenGL

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(LDFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all

