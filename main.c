/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/05 12:39:49 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*tetri;
	char	**board;

	if (argc != 2)
	{
		ft_putendl("USAGE: ./fillit [INPUT MAP]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !ft_check_end(fd))
	{
		ft_putendl_fd("error", 1);
		return (0);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	tetri = reader(fd);
	if (!tetri)
		return (0);
	align_list(tetri);
	board = solver(tetri);
	print_board(board);
	free_list(tetri);
	free_board(board);
	return (0);
}
