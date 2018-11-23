/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:38:23 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 16:45:41 by yoribeir         ###   ########.fr       */
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

char	**init_board(t_list *list)
{
	char	**board;
	int		boardsize;
	int		i;

	i = 0;
	boardsize = board_initsize(list);
	board = malloc(sizeof(char *) * boardsize);
	while (i < boardsize)
	{
		board[i] = malloc(sizeof(char) * boardsize);
		ft_memset(board[i], '.', boardsize);
		i++;
	}
	return (board);
}
