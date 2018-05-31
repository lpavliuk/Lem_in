/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:03:34 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/30 17:03:36 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst		*lstnew(t_lst *lst)
{
	while (NEXT)
		lst = NEXT;
	NEXT = malloc(sizeof(t_lst));
	NEXT->room = NULL;
	NEXT->number = 0;
	NEXT->x = 0;
	NEXT->y = 0;
	NEXT->ant = 0;
	NEXT->iter = 0;
	NEXT->prev = NULL;
	NEXT->links = NULL;
	NEXT->next = NULL;
	return (NEXT);
}

void		check_room_in_list(t_lst *lst, t_lst *new)
{
	while (NEXT)
	{
		if (!ft_strcmp(ROOM, new->room))
			ft_error(ERR_9);
		else if (X == new->x && Y == new->y)
			ft_error(ERR_10);
		else
			lst = NEXT;
	}
}

int			lstlen(t_lst *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
