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

static void	check_start(t_lst *lst)
{
	while (lst)
	{
		if (STR == 1)
		{
			if (ITER == 0)
				ft_error(ERR_14);
		}
		lst = NEXT;
	}
}

void		find_way(t_lem *lmn, t_lst *lst, t_lst *all)
{
	int		i;
	t_lst	*tmp;
	char	**str;

	i = -1;
	if (STR == 1 || !LINKS)
		return ;
	str = ft_strsplit(LINKS, ' ');
	while (str[++i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i]) && (tmp->str == 1 ||
					!tmp->was || tmp->iter > ITER))
			{
				tmp->was = 1;
				tmp->iter = ITER + 1;
				tmp->prev = ROOM;
				find_way(lmn, tmp, all);
			}
			tmp = tmp->next;
		}
	}
	freeshka_str(str);
}

void		algorithm(t_lem *lmn, t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->en == 1)
			break ;
		tmp = tmp->next;
	}
	tmp->was = 1;
	find_way(lmn, tmp, lst);
	check_start(lst);
	tmp = lst;
	while (tmp)
	{
		if (tmp->str == 1)
			break ;
		tmp = tmp->next;
	}
	write_road(lmn, tmp, lst, -1);
}
