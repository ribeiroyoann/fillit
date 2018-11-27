/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/27 17:13:53 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_piece(char **tetri, char **board, int x, int y)
{
	int 	i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#' && board[x + i][j + y] == '.')
			{
				count++;
				if (count == 4)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		valid_piece(char **tetri, char **board, int x, int y, int c)
{
	int		i;
	int		j;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				board[i + x][j + y] = c;
			j++;
		}
		i++;
	}
	return (1);
}

int		align_piece(char **tetri)
{
	int i;
	int j;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		align_piece3(char **tetri)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[j][i] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		solve(t_list *list, char **board, int boardsize, int x, int y)
{
	int		letter;

	y = 0;
	letter = 'A';
	while (y < boardsize)
	{
		x = 0;
		while (x < boardsize)
		{
			if (place_piece(list->content, board, x, y))
			{
				if (valid_piece(list->content, board, x, y, letter))
					{
						if (!list->next)
							return 1;
						solve(list->next, board, boardsize, x, y);
					}
			}
			else
				return 0;
			x++;
		}
		y++;
	}
	return (1);
}

char	**solver(t_list *list)
{
	char	**board;
	int		boardsize;

	boardsize = board_initsize(list);
	board = init_board(list, boardsize);
	while (1)
	{
		print_board(board);
		if (!solve(list, board, boardsize, 0, 0))
		{
			boardsize++;
			free(board);
			init_board(list, boardsize);
		}
		else
			return (board);
	}
}