/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 16:45:41 by yoribeir         ###   ########.fr       */
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

int		solve(t_list *list, char **board)
{
	int x;
	int y;
	int letter;
	int	offsetx;
	int	offsety;

	y = 0;
	x = 0;
	letter = 'A';
	while (list->next)
	{
		printf("y = %d ; ", align_piece(list->content));
		printf("x = %d\n", align_piece3(list->content));
		offsety = align_piece(list->content);
		offsetx = align_piece3(list->content);
		if (place_piece(list->content, board, (y - offsety), (x - offsetx)))
		{
			valid_piece(list->content, board, (y - offsety), (x - offsetx), letter);
			y++;
			x++;
			letter++;
		}
		list = list->next;
	}
	return (1);
}
