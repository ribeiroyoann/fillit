/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:08:56 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/20 18:16:44 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_list_push_back(t_tetri **list, t_tetri *new)
{
	t_tetri		*tmp;

	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}


t_tetri		*ft_list_new(void)
{
	t_tetri		*node;

	if (!(node = malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(node->shape = malloc(sizeof(char *) * 5)))
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int			ft_list_size(t_tetri *head)
{
	int			count;
	t_tetri		*tmp;


	tmp = head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
