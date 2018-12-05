/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:36:49 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 12:33:15 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	print_tetri(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		ft_putendl(tetri[i]);
		i++;
	}
	ft_putchar('\n');
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
