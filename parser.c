/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:19 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/21 10:44:48 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parser(int fd)
{
	unsigned int	i;
	char			*line;
	t_tetri			*list;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < 5)
	{
		if (!i)
			list = ft_list_new();
		list->shape[i] = ft_strdup(line);
		// printf("[%s]\n", list->shape[i]);
		i++;
		if (i == 4)
		{
			ft_list_push_back(&list, list);
			printf("[%s]\n", list->shape[0]);
			i = 0;
		}
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
			if (line[i] != '.' || line[i] != '#' || i > 3)
				return (NULL);
			i++;
		}
		return (line);
	}
	return (NULL);
}

char	**get_tetri(int fd)
{
	int		i;
	char	**tetri;

	i = 0;
	if (!(tetri = ))
	while (i < 4)
	{
		tetri[i] = get_line(fd);
		i++;
	}

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