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

static void	check_end(t_lst *lst)
{
	while (lst)
	{
		if (EN == 1)
		{
			if (ITER == 0)
				ft_error(ERR_14);
		}
		lst = NEXT;
	}
}

static int	work_while(t_lem *lmn, t_lst *lst, t_lst *all, char *str)
{
	t_lst	*tmp;

	tmp = all;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, str) && (tmp->en == 1
			|| (tmp->str != 1 && ft_strcmp(ROOM, str)
			&& ((PREV && ft_strcmp(PREV, str)) || !PREV))))
		{
			tmp->iter = ITER + 1;
			tmp->prev = ROOM;
			if (tmp->en == 1)
				return (1);
			find_way(lmn, tmp, all);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		find_way(t_lem *lmn, t_lst *lst, t_lst *all)
{
	int		i;
	char	**str;

	i = 0;
	if (EN == 1 || COUNT > lmn->all_var || !LINKS)
		return ;
	str = ft_strsplit(LINKS, ' ');
	while (str[i] != 0)
	{
		COUNT++;
		if (work_while(lmn, lst, all, str[i]))
		{
			freeshka_str(str);
			return ;
		}
		i++;
	}
	freeshka_str(str);
}

void		algorithm(t_lem *lmn, t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	ALL_VAR = lstlen(lst) * lstlen(lst);
	while (tmp)
	{
		if (tmp->str == 1)
			break ;
		tmp = tmp->next;
	}
	find_way(lmn, tmp, lst);
	check_end(lst);
	tmp = lst;
	while (tmp)
	{
		if (tmp->en == 1)
			break ;
		tmp = tmp->next;
	}
	write_road(lmn, tmp, lst, 0);
}
