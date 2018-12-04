/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:49:49 by anonymous         #+#    #+#             */
/*   Updated: 2018/12/04 15:18:56 by yoribeir         ###   ########.fr       */
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
			if (tetri[i][j] == '#')
			{
				if ((y + i) >= boardsize || (j + x >= boardsize))
					return (0);
				if (board[y + i][j + x] != '.')
					return (0);
			}
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

void	align_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		align_tetrimino(tmp->content);
		tmp = tmp->next;
	}
}