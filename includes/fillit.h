/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/10 12:49:54 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TETRI_SIZE 21
# include "../libft/libft.h"

typedef struct	s_point
{
	int x;
	int	y;
}				t_point;

t_list			*reader(int fd);
char			**solver(t_list *list);
int				ft_check_end(char **argv);
t_list			*free_list(t_list *list);
void			free_board(char **board);
void			print_board(char **board);
int				board_initsize(t_list *list);
char			**init_board(int boardsize);
int				place_piece(char **tetri, char **board, t_point point,
				int boardsize);
int				valid_piece(char **tetri, char **board, t_point point, int c);
void			align_tetrimino(char **t);

#endif
