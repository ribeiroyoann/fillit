/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:36:49 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 15:38:10 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 1000

int		ft_check_end(int fd)
{
	int		ret;
	char	*tmp;
	char	buff[BUF_SIZE];

	tmp = NULL;
	while ((ret = read(fd, buff, BUF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strdup(buff);
	}
	if (!tmp || tmp[ft_strlen(tmp) - 1] != '\n' ||
			(tmp[ft_strlen(tmp) - 2] != '.' && tmp[ft_strlen(tmp) - 2] != '#'))
		return (0);
	return (1);
}

void	print_board(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		ft_putendl(board[i]);
		i++;
	}
}

void	free_board(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	free_tetri(char **tetri)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(tetri[i]);
		i++;
	}
	free(tetri);
}

t_list	*free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	while (list)
	{
		tmp = list;
		list = list->next;
		free_tetri(tmp->content);
		free(tmp);
	}
	list = NULL;
	return (NULL);
}
