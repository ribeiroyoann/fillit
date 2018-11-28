/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:49:49 by anonymous         #+#    #+#             */
/*   Updated: 2018/11/28 17:58:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_piece(char **tetri, char **board, int y, int x, int boardsize)
{
	int 	i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((x + i) >= boardsize || (j + y) >= boardsize)
				return (0);
			if ((tetri[i][j] == '#' && board[y + i][j + x] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_piece(char **tetri, char **board, int y, int x, int c)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
				board[i + y][j + x] = c;
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
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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

void	decaly(char **t)
{
	char *tmp;

	tmp = t[0];
	t[0] = t[1];
	t[1] = t[2];
	t[2] = t[3];
	t[3] = tmp;
}

void	decalx(char **t)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp = t[i][0];
		t[i][0] = t[i][1];
		t[i][1] = t[i][2];
		t[i][2] = t[i][3];
		t[i][3] = tmp;
		i++;
	}
}

void	align_tetrimino(char **t)
{
	while (!ft_strcmp(*t, "...."))
		decaly(t);
	while (t[0][0] == '.' &&
			t[1][0] == '.' &&
			t[2][0] == '.' &&
			t[3][0] == '.')
		decalx(t);
}