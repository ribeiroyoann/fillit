/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/10 13:02:33 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	fillit(char **argv)
{
	int		fd;
	t_list	*tetri;
	char	**board;

	if (!ft_check_end(argv))
	{
		ft_putendl("error");
		return ;
	}
	fd = open(argv[1], O_RDONLY);
	tetri = reader(fd);
	if (!tetri)
		return ;
	board = solver(tetri);
	print_board(board);
	close(fd);
	free_list(tetri);
	free_board(board);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("USAGE: ./fillit [INPUT MAP]");
		return (0);
	}
	else
		fillit(argv);
	return (0);
}
