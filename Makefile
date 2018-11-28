# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:25:14 by yoribeir          #+#    #+#              #
#    Updated: 2018/11/28 20:39:59 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
INCLUDES = includes
LIBS = libft
LIB = ft
FLAGS = -Wall -Werror -Wextra
SRCS = main.c reader.c check.c solver.c board.c utils.c pieces.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

.SILENT:

all : $(NAME)

%.o : $(SRCSREP)/%.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $^

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) -g $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean :
	rm -f $(OBJS)
	make clean -C libft
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
re : fclean all