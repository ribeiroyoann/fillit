/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 13:16:49 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

#include <stdio.h>

/*
** By Yalaouf, made with 🤡🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆
*/

t_list		*parser(int fd);

char		*get_line(int fd);
char		**get_tetri(int fd);

void	test_print(char **tetri);
void	print_list(t_list *lst);
int		check_blocks(char **tetri);
int		check_shape(char **tetri);


int		board_initsize(t_list *list);
char	**init_board(t_list *list);
void	print_board(char **board);

int		place_piece(char **tetri, char **board, int x, int y);
int		valid_piece(char **tetri, char **board, int x, int y, int c);
int		align_piece(char **tetri);


#endif
