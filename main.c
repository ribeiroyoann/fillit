/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/27 12:38:08 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int 	fd;
	t_list	*tetri;
	char	**board;

	fd = open(argv[1], O_RDONLY);
	tetri = parser(fd);

	board = init_board(tetri);
	solve(tetri, board);

	print_board(board);
	return 0;
}
