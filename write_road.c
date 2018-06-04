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

static int	work_while_tmp(t_lem *lmn, t_lst *lst, char **ping, int *i)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, *ping))
		{
			ROAD[*i] = ft_strdup(tmp->room);
			(*i)--;
			if (tmp->prev)
				*ping = tmp->prev;
			else if (tmp->str == 1)
				return (1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	write_to_road(t_lem *lmn, t_lst *lst, t_lst *best)
{
	int		i;
	char	*ping;
	t_lst	*tmp;

	i = best->iter + 2;
	ping = best->prev;
	ROAD = (char **)malloc(sizeof(char *) * (i + 1));
	ROAD[i--] = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->en == 1)
			break ;
		tmp = tmp->next;
	}
	ROAD[i--] = ft_strdup(tmp->room);
	if (i >= 0)
		ROAD[i--] = ft_strdup(best->room);
	while (i >= 0)
	{
		if (work_while_tmp(lmn, lst, &ping, &i))
			return ;
	}
}

void		write_road(t_lem *lmn, t_lst *lst, t_lst *all, int i)
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
				&& (tmp->iter || (!tmp->iter && tmp->str == 1))
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
