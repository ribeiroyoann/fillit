/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:46:34 by anonymous         #+#    #+#             */
/*   Updated: 2018/11/28 20:49:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define TETRI_SIZE 21

int		check_buffer(char *buffer)
{
	int		i;
	int		count;

	i = 0;
	printf("%s\n", 	buffer);
	while (buffer[i])
	{
		printf(YEL"%d [%c]\n"RESET, (i % 4), buffer[i]);
		if (buffer[i] == '#')
			count++;
		if (i % 4 == 0 && buffer[i] != '\n')
		{
			printf(RED"%c\n"RESET,	buffer[i]);
			return (0);
		}
		if (i % 4 && (buffer[i] != '#' || buffer[i] != '.'))
			return (0);
		i++;
	}
	return (count == 4);
}

char	**get_tetris(char *buffer)
{
	int		i;
	int		start;
	char	**tetri;

	i = 0;
	start = 0;
	tetri = malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		tetri[i] = ft_strsub(buffer, start, 4);
		i++;
		start += 5;
	}
	tetri[i] = 0;
	return (tetri);
}

int		reader(int fd)
{
	int		readsz;
	char	buffer[TETRI_SIZE + 1];
	char	**tetri;
	t_list	*list;

	list = NULL;
	while ((readsz = read(fd, buffer, TETRI_SIZE)))
	{
		buffer[readsz] = '\0';
		if (check_buffer(buffer))
		{
			printf("OK\n");
			tetri = get_tetris(buffer);
		}
		if (check_shape(tetri))
			ft_lstpushback(&list, ft_lstnew(tetri, 32));
		else
		{
			printf("ERROR\n");
			free_list(list);
			return (0);
		}
	}
	print_list(list);
	return (1);
}
