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

//int			listlen(t_lst *list)
//{
//	int i;
//
//	i = 0;
//	if (!list)
//		return (0);
//	while (list)
//	{
//		list = list->next;
//		i++;
//	}
//	return (i);
//}

t_lst		*lstnew(t_lst *lst)
{
	while (NEXT)
		lst = NEXT;
	NEXT = malloc(sizeof(t_lst));
	NEXT->room = NULL;
	NEXT->x = 0;
	NEXT->y = 0;
	NEXT->links = NULL;
	NEXT->next = NULL;
	return (NEXT);
}


