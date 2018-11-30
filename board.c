/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:38:23 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/30 19:05:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_initsize(t_list *list)
{
	int		lstsize;
	int		boardsize;

	lstsize = ft_lstsize(list);
	boardsize = 4;
	while (boardsize * boardsize < lstsize * 4)
		boardsize++;
	return (boardsize);
}

char	**init_board(t_list *list, int boardsize)
{
	char	**board;
	int		i;

	i = 0;
	if (!(board = malloc(sizeof(char *) * boardsize)))
		return (NULL);
	while (i < boardsize)
	{
		if (!(board[i] = malloc(sizeof(char) * boardsize)))
			return (NULL);
		ft_memset(board[i], '.', boardsize);
		i++;
	}
	board[i] = 0;
	return (board);
}
