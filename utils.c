/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:36:49 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/04 18:01:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_list(t_list *lst)
{
	t_list *tmp;
	int i;

	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (((char **)tmp->content)[i])
		{
			printf("%s\n", ((char **)tmp->content)[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_board(char **board)
{
	int i = 0;

	while (board[i])
	{
		printf("%s\n", board[i]);
		i++;
	}
	printf("\n");
}

void	print_tetri(char **tetri)
{
	int i = 0;

	while (tetri[i])
	{
		printf(CYN"%s\n"RESET, tetri[i]);
		i++;
	}
	printf("\n");
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
