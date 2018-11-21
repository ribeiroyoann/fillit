/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:51:05 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/21 18:59:00 by yoribeir         ###   ########.fr       */
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

int		check_shape(char **tetri)
{
	
}
