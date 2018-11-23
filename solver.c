/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:29:02 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 13:16:23 by yoribeir         ###   ########.fr       */
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
			{
				board[i + x][j + y] = c;
			}
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
	// int	imax;
	// int	jmax;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				return (i - 1);
			j++;
		}
		i++;
	}
	return (0);
}
