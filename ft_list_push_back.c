/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumaysou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:02:57 by oumaysou          #+#    #+#             */
/*   Updated: 2018/11/20 15:13:01 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_push_back(t_tetri **list, t_tetri *new)
{
	t_tetri *tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
