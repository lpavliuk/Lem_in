/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:52:44 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/31 19:52:46 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 	find_way(t_lem *lmn, t_lst *lst, t_lst *all, int c)
{
	int		i;
	char	**str;
	t_lst	*tmp;

	if (EN == 1 || !LINKS)
		return (1);
	i = 0;
	str = ft_strsplit(LINKS, ' ');
	while (str[i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i]) && ft_strcmp(ROOM, str[i]))
			{
				tmp->iter = lst->iter + 1;
				tmp->prev = ROOM;
				if (find_way(lmn, tmp, lst, c))
					return (1);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
//	ft_stralldel(str, i);
//	free(str);
}

void	algorithm(t_lem *lmn, t_lst *lst)
{
	int		c;
	t_lst	*tmp;

	while (MAP[c] != 0)
		c++;
	tmp = lst;
	while (tmp)
	{
		if (tmp->str == 1)
			break ;
		tmp = tmp->next;
	}
	find_way(lmn, tmp, lst, c);
}
