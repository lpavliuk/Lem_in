/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:41:21 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/04 15:41:22 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	do_link_prev(t_lem *lmn)
{
	t_road *prev;
	t_road *tmp;

	tmp = L_ROAD;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp)
			tmp->prev = prev;
	}
}

void	show_road(t_lem *lmn, t_lst *lst)
{
	t_road	*step;
	t_road	*end;
	t_road	*tmp;

	tmp = L_ROAD;
	do_link_prev(lmn);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->ant < NUM_A)
	{
		step = L_ROAD->next;
		while (step)
		{
			if (step->ant >= 0 && step->ant < NUM_A)
			{
				step->ant++;
				if (step->ant == 1)
					break ;
			}
			else
				step->ant++;
			step = step->next;
		}
		end = tmp;
		while (end)
		{
			if (end->ant && end->ant <= NUM_A)
			{
				ft_printf("L%d-%s", end->ant, end->link->room);
				if (end->link->str != 1)
					ft_printf(" ");
			}
			end = end->prev;
		}
		ft_printf("\n");
	}
}
