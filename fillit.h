/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/21 18:53:59 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

#include <stdio.h>

/*
** By Yalaouf, made with 🤡🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆🍆
*/

typedef struct		s_tetri
{
	char			**shape;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

int			parser(int fd);
t_tetri		*ft_list_new(void);
int			ft_list_size(t_tetri *head);
void		ft_list_push_back(t_tetri **list, char **tetri);

char	*get_line(int fd);
char		**get_tetri(int fd);

void	test_print(char **tetri);
void	print_list(t_list *lst);
int		check_blocks(char **tetri);

#endif
