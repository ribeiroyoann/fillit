/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 14:46:24 by oumaysou         ###   ########.fr       */
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
	while (get_next_line(fd, &line) == 1 && i < 4)
	{
		if (!i)
			if ((list->shape = (char **)malloc(sizeof(char *) * 5)) == NULL)
				return (0);
		if (!(i % 4))
			(list->shape)[i] = ft_strdup(*line);
		i++;
		if (i == 4)
		{	
			list->shape[i] = 0;
			list = list->next;
			i = 0;
		}
	}
	return (1);
}
