/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/28 18:02:19 by anonymous        ###   ########.fr       */
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

// PARSER //

t_list		*parser(int fd);
char		*get_line(int fd);
char		**get_tetri(int fd);

// READER //

int		reader(int fd);
char	**get_tetris(char *buffer);

// SOLVER //

int		solve(t_list *list, char **board, int boardsize, int letter);
char	**solver(t_list *list);

// CHECK //

int		check_blocks(char **tetri);
int		check_shape(char **tetri);

// UTILS //

void	print_tetri(char **tetri);
void	free_list(t_list *list);
void	free_map(char **board, int boardsize);
void	check_offset(t_list *list);
void	print_list(t_list *lst);
void	print_board(char **board);
void	test_print(char **tetri);

// BOARD //

int		board_initsize(t_list *list);
char	**init_board(t_list *list, int boardsize);

// PIECES //

int		place_piece(char **tetri, char **board, int x, int y, int boardsize);
int		valid_piece(char **tetri, char **board, int x, int y, int c);
int		align_piece(char **tetri);
int		align_piece3(char **tetri);

void	align_tetrimino(char **t);
void	align_list(t_list *list);

#endif
