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

void	show_road(t_lem *lmn, t_lst *lst)
{
	int 	i;
	int 	all;
	char	**str;
	t_road	*step;
	t_lst	*tmp;

	i = 0;
	all = 1;
	while (all <= NUM_A)
	{
		step = L_ROAD->next;
		while (step)
		{
			if (!step->link->ant)
			{
				step->link->ant++;
				step->link->number = all;
				ft_printf("L%d-%s", NUMBER, step->link->room);
			}
			else
			{
				step->link->next->ant++;
				step->link->next->number = step->link->number;
				ft_printf("L%d-%s", step->link->number, step->next->link->room);
			}
			step = step->next;
		}
		all++;
	}
}
