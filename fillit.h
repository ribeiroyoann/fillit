/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/27 16:38:41 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*
** By Yalaouf, made with 🤡🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆
*/

t_list		*parser(int fd);

int		reader(int fd);
char	**get_tetris(char *buffer);
void	print_tetri(char **tetri);
void	free_list(t_list *list);
void	free_map(char **board, int boardsize);

char		*get_line(int fd);
char		**get_tetri(int fd);

void	test_print(char **tetri);
void	print_list(t_list *lst);
int		check_blocks(char **tetri);
int		check_shape(char **tetri);


int		board_initsize(t_list *list);
char	**init_board(t_list *list, int boardsize);
void	print_board(char **board);

int		place_piece(char **tetri, char **board, int x, int y);
int		valid_piece(char **tetri, char **board, int x, int y, int c);
int		align_piece(char **tetri);
int		align_piece3(char **tetri);
int		solve(t_list *list, char **board, int boardsize, int x, int y);
char	**solver(t_list *list);


#endif
