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

void		freeshka_str(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	find_way(t_lem *lmn, t_lst *lst, t_lst *all)
{
	int		i;
	char	**str;
	t_lst	*tmp;

	if (EN == 1)
		return (1);
	if (!LINKS)
		return (0);
	i = 0;
	str = ft_strsplit(LINKS, ' ');
	while (str[i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i]) && tmp->en == 1)
			{
				tmp->iter = ITER + 1;
				tmp->prev = ROOM;
				ft_printf("%s - ", ROOM);
				if (find_way(lmn, tmp, all))
				{
					freeshka_str(str);
					return (1);
				}
			}
			tmp = tmp->next;
		}
		i++;
	}
	i = 0;
	while (str[i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i]) && tmp->str != 1
				&& ft_strcmp(ROOM, str[i])
				&& ((PREV && ft_strcmp(PREV, str[i])) || !PREV))
			{
				tmp->iter = ITER + 1;
				tmp->prev = ROOM;
				ft_printf("%s - ", ROOM);
				if (find_way(lmn, tmp, all))
				{
					freeshka_str(str);
					return (1);
				}
			}
			tmp = tmp->next;
		}
		i++;
	}
	freeshka_str(str);
	return (0);
}

void	algorithm(t_lem *lmn, t_lst *lst)
{

	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->str == 1)
			break ;
		tmp = tmp->next;
	}
	if (find_way(lmn, tmp, lst))
		ft_printf("\nFIND: 1\n");
	else
		ft_printf("\nFIND: 0\n");
}
