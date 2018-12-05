/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 12:25:14 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_list *list, char **board, int boardsize, int letter)
{
	t_point	point;

	if (list == NULL)
		return (1);
	point.y = 0;
	while (point.y < boardsize)
	{
		point.x = 0;
		while (point.x < boardsize)
		{
			if (place_piece(list->content, board, point, boardsize))
			{
				valid_piece(list->content, board, point, letter);
				if (solve(list->next, board, boardsize, letter + 1))
					return (1);
				else
					valid_piece(list->content, board, point, '.');
			}
			point.x++;
		}
		point.y++;
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
