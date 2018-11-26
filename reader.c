/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:46:34 by anonymous         #+#    #+#             */
/*   Updated: 2018/11/26 18:16:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define TETRI_SIZE 21

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
		{
			printf("CHECK LINE\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_tetri(char **tetri)
{
	int		y;
	int		i;
	int		count;
	int		countl;

	y = 0;
	count = 0;
	countl = 0;
	while (tetri[y])
	{
		i = 0;
		if (!check_line(tetri[y]))
			return (0);
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
	printf("CHECK TETRI\n");
	return (0);
}

int		check_buffer(char *buffer)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	printf("LINE %d\n", count);
	if (count == 5)
		return (1);
	printf("CHECK BUFFER\n");
	return (0);
}

char	**get_tetris(char *buffer)
{
	int		i;
	int		start;
	char	**tetri;

	i = 0;
	start = 0;
	tetri = malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		tetri[i] = ft_strsub(buffer, start, 4);
		i++;
		start += 5;
	}
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
			tetri = get_tetris(buffer);
		if (check_tetri(tetri) && check_shape(tetri))
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
