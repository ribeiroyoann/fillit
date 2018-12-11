/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/11 14:44:52 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char **argv)
{
	int		fd;
	t_list	*tetri;
	char	**board;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !ft_check_end(fd))
	{
		ft_putendl("error");
		return ;
	}
	close(fd);
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
