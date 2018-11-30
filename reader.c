/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:46:34 by anonymous         #+#    #+#             */
/*   Updated: 2018/11/30 18:17:54 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define TETRI_SIZE 21

int		check_links(char *buffer)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			if (buffer[i + 1] == '#')
				count++;
			if (buffer[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 3 || count == 4);
}

int		check_buffer(char *buffer)
{
	int		i;
	int		count;
	int		offset;

	i = 0;
	count = 0;
	offset = 4;
	while (buffer[i])
	{
		if (buffer[i] != '#' && buffer[i] != '.' && buffer[i] != '\n')
		{
			printf("ERROR CHARS\n");
			return (0);
		}
		if (buffer[offset] != '\n' && offset < 16)
		{
			printf("ERROR NEWL\n");
			return (0);
		}
		if (buffer[i] == '#')
			count++;
		if (offset > 20)
		{
			offset++;
			if (buffer[offset] == '\n')
				return (0);
		}
		offset += 5;
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
		if (!check_buffer(buffer))
		{
			printf("ERROR BUFFER\n");
			return (0);
		}
		if (!check_links(buffer))
		{
			printf("ERROR LINKS\n");
			return (0);
		}
		tetri = get_tetris(buffer);
		print_tetri(tetri);
		ft_lstpushback(&list, ft_lstnew(tetri, 32));
	}
	return (1);
}
