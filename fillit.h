* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:17:29 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 14:19:49 by oumaysou         ###   ########.fr       */
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
}					t_tetri;

int		parser(char **argv);

#endif
