/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/30 20:05:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int 	fd;
	t_list	*tetri;
	char	**board;

	if (argc != 2)
	{
		ft_putendl("USAGE: ./fillit [INPUT MAP]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	tetri = reader(fd);
	if (!tetri)
		return (0);
	align_list(tetri);
	print_list(tetri);
	board = solver(tetri);
	print_board(board);
	free_list(tetri);
	free_board(board);
	return 0;
}
