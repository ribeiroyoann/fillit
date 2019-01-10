/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:48:03 by oumaysou          #+#    #+#             */
/*   Updated: 2018/12/18 19:46:59 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_piece(char **tetri, char **board, t_point point, int boardsize)
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
			{
				if ((point.y + i) >= boardsize || (j + point.x >= boardsize))
					return (0);
				if (board[point.y + i][j + point.x] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_piece(char **tetri, char **board, t_point point, int c)
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
				board[i + point.y][j + point.x] = c;
			j++;
		}
		i++;
	}
	return (1);
}

void	align_y(char **t)
{
	char *tmp;

	tmp = t[0];
	t[0] = t[1];
	t[1] = t[2];
	t[2] = t[3];
	t[3] = tmp;
}

void	align_x(char **t)
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
		align_y(t);
	while (t[0][0] == '.' &&
			t[1][0] == '.' &&
			t[2][0] == '.' &&
			t[3][0] == '.')
		align_x(t);
}
