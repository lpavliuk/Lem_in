/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:31:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/04 12:31:53 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_road	*new_road_elem(t_road *all)
{
	while (all->next)
		all = all->next;
	all->next = malloc(sizeof(t_road));
	all->next->link = NULL;
	all->next->next = NULL;
	return (all->next);
}

static int		write_to_list(t_lem *lmn, t_lst *lst, char *ping)
{
	t_lst	*tmp;
	t_road	*all;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, ping))
		{
			all = new_road_elem(L_ROAD);
			all->link = tmp;
			if (tmp->prev)
				ping = tmp->prev;
			else if (tmp->en == 1)
				return (1);
			tmp = lst;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void		write_to_road(t_lem *lmn, t_lst *lst, t_lst *best)
{
	t_lst	*tmp;
	t_road	*all;

	all = L_ROAD;
	tmp = lst;
	while (tmp)
	{
		if (tmp->str == 1)
			break ;
		tmp = tmp->next;
	}
	all->link = tmp;
	all = new_road_elem(L_ROAD);
	all->link = best;
	if (best->prev && write_to_list(lmn, lst, best->prev))
		return ;
}

void			write_road(t_lem *lmn, t_lst *lst, t_lst *all, int i)
{
	char	**str;
	t_lst	*tmp;
	t_lst	*best;
	int		steps;

	steps = 0;
	str = ft_strsplit(LINKS, ' ');
	while (str[i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i])
				&& (tmp->iter || (!tmp->iter && tmp->en == 1))
				&& (!steps || steps >= tmp->iter))
			{
				steps = tmp->iter;
				best = tmp;
			}
			tmp = tmp->next;
		}
		i++;
	}
	ft_printf("best room: %s\niter: %d\n", best->room, best->iter);
	write_to_road(lmn, all, best);
	freeshka_str(str);
}
