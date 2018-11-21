/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/21 13:17:46 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parser(int fd)
{
	char **tetri;
	int y = 0;

	tetri = get_tetri(fd);
	while (tetri[y])
	{
		printf("%s\n", tetri[y]);
		y++;
	}
	return (1);
}

char	*get_line(int fd) // returns 1 line from GNL and checks errors
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) == 1)
	{
		while (line[i])
		{
			if ((line[i] != '.' && line[i] != '#')|| i > 3)
				return (NULL);
			i++;
		}
		if (i == 4 || !ft_strcmp(line, "\n"))
			return (line);
	}
	return (NULL);
}

char	**get_tetri(int fd)
{
	int		i;
	char	**tetri;
	char	*stock;

	i = 0;
	if (!(tetri = malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 5)
	{
		stock = get_line(fd);
		if (i < 4)
			tetri[i] = ft_strdup(stock);
		i++;
	}
	tetri[i - 1] = 0;
	if (i == 5)
		return (tetri);
	return (NULL);
}

// parser()
// {
// 	*line = char *read_line(fd)
// 	{
// 		if (check_line(*line) == 1)
// 			return (line);
// 	}
// 	char **	create_shape(*line)
// 	{
		
// 		char tab[i] = ft_strdup(line);

// 	}
// }