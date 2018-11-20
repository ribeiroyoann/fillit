/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 18:57:20 by yoribeir         ###   ########.fr       */
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

int			parser(char **argv);
t_tetri		*ft_list_new(void);
int			ft_list_size(t_tetri *head);
void		ft_list_push_back(t_tetri **list, t_tetri *new);
void		ft_lst_add(t_tetri **alst, t_tetri *new);

#endif
