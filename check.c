/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:51:05 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/28 17:49:01 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_blocks(char **tetri)
{
	int y;
	int i;
	int	count;

	y = 0;
	count = 0;
	while (tetri[y])
	{
		i = 0;
		while (tetri[y][i])
		{
			if (tetri[y][i] == '#')
				count++;
			i++;
		}
		y++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		check_around(char **tetri, int x, int y)
{
	int		count;

	count = 0;
	if (tetri[x + 1] && tetri[x + 1][y] == '#')
		count++;
	if (tetri[x - 1] && tetri[x - 1][y] == '#')
		count++;
	if (tetri[x][y + 1] && tetri[x][y + 1] == '#')
		count++;
	if (tetri[x][y - 1] && tetri[x][y - 1] == '#')
		count++;
	return (count);
}

int		check_shape(char **tetri)
{
	int x;
	int y;
	int	ret;

	y = 0;
	ret = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y][x] == '#')
				ret += check_around(tetri, y, x);
			x++;
		}
		y++;
	}
	printf(RED"ret %d\n"RESET, ret);
	return ((ret == 6) || (ret == 8));
}
