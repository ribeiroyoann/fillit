/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 11:26:34 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetrimino(char *buffer)
{
	int		i;

	i = 0;
	while (i < 4 && buffer[i])
	{
		if (buffer[i] != '.' || buffer[i] != '#')
		{
			printf("[%c]\n", buffer[i]);
			return (-1);
		}
		i++;
	}
	return (1);
}

int		parser(char **argv)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("[%s]", line);
	}

	return (1);
}
