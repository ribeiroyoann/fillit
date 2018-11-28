/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:36:49 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/28 17:45:14 by anonymous        ###   ########.fr       */
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

	printf("\n");
	while (board[i])
	{
		printf("%s\n", board[i]);
		i++;
	}
}

void	print_tetri(char **tetri)
{
	int i = 0;

	printf("\n");
	while (tetri[i])
	{
		printf(CYN"%s\n"RESET, tetri[i]);
		i++;
	}
}

void	free_map(char **board, int boardsize)
{
	int		y;

	y = 0;
	while (y < boardsize)
	{
		free(board[y]);
		y++;
	}
	free(board);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		ft_memdel((void *)&tmp);
	}
}

void	check_offset(t_list *list)
{
	t_list *tmp;
	int		offsetx;
	int		offsety;

	tmp = list;
	offsety = align_piece(list->content);
	offsetx = align_piece3(list->content);
	while (tmp)
	{
		printf("%d %d\n", offsetx, offsety);
		print_tetri(tmp->content);
		tmp = tmp->next;
	}
}
