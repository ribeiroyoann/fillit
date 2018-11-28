/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/28 17:50:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_list *list, char **board, int boardsize, int letter)
{
	int		x;
	int		y;
	int		offsetx;
	int		offsety;

	if (list == NULL)
		return (1);
	y = 0;
	while (y < boardsize)
	{
		x = 0;
		while (x < boardsize)
		{
			offsety = align_piece(list->content);
			offsetx = align_piece3(list->content);
			if (place_piece(list->content, board, (y - offsety), (x - offsetx), boardsize))
			{
				valid_piece(list->content, board, (y - offsety), (x - offsetx), letter);
				letter++;
 				if (solve(list->next, board, boardsize, letter))
 					return (1);
				else
					valid_piece(list->content, board, (y - offsety), (x - offsetx), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**solver(t_list *list)
{
	char	**board;
	int		boardsize;
	int		letter;

	check_offset(list);
	boardsize = board_initsize(list);
	board = init_board(list, boardsize);
	letter = 'A';
	while (!(solve(list, board, boardsize, letter)))
	{
		boardsize++;
		free(board);
		board = init_board(list, boardsize);
	}
	return (board);
}