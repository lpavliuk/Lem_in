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

static void	write_to_road(t_lem *lmn, t_lst *lst, t_lst *best)
{
	int		i;
	t_lst	*tmp;
	char	*ping;

	i = best->iter;
	ping = best->prev;
	ROAD = (char **)malloc(sizeof(char *) * (i + 1));
	ROAD[i--] = 0;
	if (i >= 0)
		ROAD[i--] = ft_strdup(best->room);
	while (i >= 0)
	{
		tmp = lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, ping))
			{
				ROAD[i--] = ft_strdup(tmp->room);
				if (tmp->prev)
					ping = tmp->prev;
				else
					return ;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void		write_road(t_lem *lmn, t_lst *lst, t_lst *all, int i)
{
	int		c;
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
				&& (!steps || steps >= tmp->iter))
			{
				steps = tmp->iter;
				best = tmp;
			}
			tmp = tmp->next;
		}
		i++;
	}
	write_to_road(lmn, all, best);
	c = 0;
	while (ROAD[c] != 0)
	{
		ft_printf("%s\n", ROAD[c]);
		c++;
	}
	freeshka_str(str);
}
