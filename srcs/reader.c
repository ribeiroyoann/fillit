/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:22:13 by oumaysou          #+#    #+#             */
/*   Updated: 2018/12/11 14:46:35 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		check_newline(char *buffer)
{
	int i;

	i = 4;
	while (i < 20)
	{
		if (buffer[i] != '\n')
			return (0);
		i += 5;
	}
	if (buffer[i - 4] == '\n')
		return (1);
	if (buffer[i - 4] == '\0')
		return (2);
	return (0);
}

int		check_buffer(char *buffer)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (check_newline(buffer) == 0)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] != '#' && buffer[i] != '.' && buffer[i] != '\n')
			return (0);
		if (buffer[i] == '#')
			count++;
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
	tetri = ft_memalloc(sizeof(char *) * 5);
	while (i < 4)
	{
		tetri[i] = ft_strsub(buffer, start, 4);
		i++;
		start += 5;
	}
	tetri[i] = 0;
	return (tetri);
}

t_list	*reader(int fd)
{
	int		readsz;
	char	buffer[TETRI_SIZE + 1];
	char	**tetri;
	t_list	*list;

	list = NULL;
	while ((readsz = read(fd, buffer, TETRI_SIZE)))
	{
		buffer[readsz] = '\0';
		if (check_buffer(buffer) && check_links(buffer))
		{
			tetri = get_tetris(buffer);
			align_tetrimino(tetri);
			ft_lstpushback(&list, ft_lstnew(tetri, 32));
			free(tetri);
		}
		else if (!check_buffer(buffer) || !check_links(buffer) ||
			ft_lstsize(list) > 26)
		{
			ft_putendl("error");
			return (free_list(list));
		}
	}
	return (list);
}
