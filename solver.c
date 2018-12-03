/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/30 20:05:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_list *list, char **board, int boardsize, int letter)
{
	int		x;
	int		y;

	if (list == NULL)
		return (1);
	y = 0;
	while (y < boardsize)
	{
		x = 0;
		while (x < boardsize)
		{
			if (place_piece(list->content, board, y, x, boardsize))
			{
				printf("OK\n");
				valid_piece(list->content, board, y, x, letter);
 				if (solve(list->next, board, boardsize, letter + 1))
 					return (1);
				else
					valid_piece(list->content, board, y, x, '.');
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

	boardsize = board_initsize(list);
	if (!(board = init_board(list, boardsize)))
		return (NULL);
	letter = 'A';
	while (!(solve(list, board, boardsize, letter)))
	{
		free_board(board);
		boardsize++;
		if (!(board = init_board(list, boardsize)))
			return (NULL);
	}
	return (board);
}