/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 19:33:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parser(char **argv)
{
	int				fd;
	unsigned int	i;
	char			*line;
	t_tetri			*list;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1 && i < 5)
	{
		if (!i)
			list = ft_list_new();
		list->shape[i] = ft_strdup(line);
		printf("[%s]\n", list->shape[i]);
		i++;
		if (i == 4)
		{
			ft_list_push_back(&list, list);
			i = 0;
		}
	}
	return (1);
}
