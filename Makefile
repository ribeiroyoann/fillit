# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:25:14 by yoribeir          #+#    #+#              #
#    Updated: 2018/12/21 15:39:10 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INCLUDES = includes
LIBS = libft
LIB = ft
# FLAGS = -Wall -Werror -Wextra
SRCS = main.c reader.c solver.c board.c utils.c pieces.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCSREP)/%.c
	gcc $(FLAGS) -I$(INCLUDES) -c $^

$(NAME): $(OBJS)
	@make -C libft
	gcc $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
re: fclean all
