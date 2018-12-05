/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumaysou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:31:41 by oumaysou          #+#    #+#             */
/*   Updated: 2018/12/05 12:29:47 by oumaysou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 50000

int		ft_check_end(int fd)
{
	int		ret;
	char	*tmp;
	char	buff[BUF_SIZE];

	tmp = NULL;
	while ((ret = read(fd, buff, BUF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strdup(buff);
	}
	if (!tmp || tmp[ft_strlen(tmp) - 1] != '\n' ||
			(tmp[ft_strlen(tmp) - 2] != '.' && tmp[ft_strlen(tmp) - 2] != '#'))
		return (0);
	return (1);
}

void	align_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		align_tetrimino(tmp->content);
		tmp = tmp->next;
	}
}
