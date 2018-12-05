/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 12:53:56 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_line(int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == 1)
		return (line);
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
	while (i < 4)
	{
		stock = get_line(fd);
		if (!(tetri[i] = ft_strdup(stock)))
			return (NULL);
		i++;
	}
	tetri[i] = 0;
	stock = get_line(fd);
	return (tetri);
}

int		parser(int fd)
{
	char	**tetri;
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (((tetri = get_tetri(fd)) != NULL))
	{
		if (check_blocks(tetri) && check_shape(tetri))
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
	print_list(list);
	return (1);
}
