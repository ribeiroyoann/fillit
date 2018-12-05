/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:38:23 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 15:19:42 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_initsize(t_list *list)
{
	int		lstsize;
	int		boardsize;

	lstsize = ft_lstsize(list);
	boardsize = 1;
	while (boardsize * boardsize < lstsize * 4)
		boardsize++;
	return (boardsize);
}

char	**init_board(int boardsize)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	board = ft_memalloc(sizeof(char *) * boardsize + 1);
	while (i < boardsize)
	{
		board[i] = ft_strnew(boardsize);
		j = 0;
		while (j < boardsize)
			board[i][j++] = '.';
		i++;
	}
	board[i] = 0;
	return (board);
}
