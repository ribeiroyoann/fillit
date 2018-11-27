# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:25:14 by yoribeir          #+#    #+#              #
#    Updated: 2018/11/27 11:46:33 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
INCLUDES = includes
LIBS = libft
LIB = ft
FLAGS = -Wall -Werror -Wextra
SRCS = main.c parser.c check.c solver.c board.c utils.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

.SILENT:

all : $(NAME)

%.o : $(SRCSREP)/%.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $^

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean :
	rm -f $(OBJS)
	make clean -C libft
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
re : fclean all