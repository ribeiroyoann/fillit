/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 12:37:17 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) == 1)
	{
		while (line[i])
		{
			if ((line[i] != '.' && line[i] != '#') || i > 3)
				return (NULL);
			i++;
		}
		if (i == 4)
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
			if (!(tetri[i] = ft_strdup(stock)))
				return NULL;
		i++;
	}
	tetri[i - 1] = 0;
	if (i == 5)
		return (tetri);
	return (NULL);
}

t_list		*parser(int fd)
{
	char 	**tetri;
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (((tetri = get_tetri(fd)) != NULL))
	{
		if (check_blocks(tetri))
		{
			node = ft_lstnew(tetri, 32);
			ft_lstpushback(&list, node);
		}
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	return (list);
}
