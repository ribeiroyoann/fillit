/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:51:05 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/22 11:35:06 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_blocks(char **tetri)
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

int	check_around(char **tetri, int x, int y)
{
	if (tetri[x + 1][y] && tetri[x + 1][y] == '#')
		return (1);
	if (tetri[x - 1][y] && tetri[x - 1][y] == '#')
		return (1);
	if (tetri[x][y + 1] && tetri[x][y + 1] == '#')
		return (1);
	if (tetri[x][y - 1] && tetri[x][y - 1] == '#')
		return (1);
	return (0);
}

int	check_shape(char **tetri)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tetri[x])
	{
		while (tetri[x][y])
		{
			if (tetri[x][y] == '.' || (tetri[x][y] == '#' &&
						check_around(tetri, x, y)))
				y++;
			else
				return(0);
		}
		x++;
	}
	return (1);	
}
