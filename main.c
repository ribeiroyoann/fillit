/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/28 20:43:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int 	fd;
	t_list	*tetri;
	char	**board;

	fd = open(argv[1], O_RDONLY);


	reader(fd);
	// tetri = parser(fd);
	// print_list(tetri);
	// align_list(tetri);
	// board = solver(tetri);
	// print_board(board);

	return 0;
}
