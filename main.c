/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/23 13:19:52 by yoribeir         ###   ########.fr       */
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
	print_list(tetri);

	printf("-----\n\n");

	board = init_board(tetri);
	while (tetri->next)
	{
		printf("%d\n", align_piece(tetri->content));
		if (place_piece(tetri->content, board, 0, 0))
			valid_piece(tetri->content, board, 0, 0, 'A');
		tetri = tetri->next;
	}
	print_board(board);
	return 0;
}
