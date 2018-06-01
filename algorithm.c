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
				if (tmp->iter && tmp->iter < ITER)
					break ;
				tmp->iter = ITER + 1;
				tmp->prev = ROOM;
				ft_printf("%s - ", ROOM);
				find_way(lmn, tmp, all);
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
				find_way(lmn, tmp, all);
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
//static void	find_way(t_lem *lmn, t_lst *lst, t_lst *all, int i)
//{
//	char	**str;
//	t_lst	*tmp;
//
//	if (EN == 1 || !LINKS)
//		return ;
//	str = ft_strsplit(LINKS, ' ');
//	while (str[i] != 0)
//	{
//		tmp = all;
//		while (tmp)
//		{
//			if (!ft_strcmp(tmp->room, str[i]) && (tmp->en == 1 || (tmp->str != 1
//				&& ft_strcmp(ROOM, str[i])
//				&& ((PREV && ft_strcmp(PREV, str[i])) || !PREV))))
//			{
//				tmp->iter = ITER + 1;
//				tmp->prev = ROOM;
//				find_way(lmn, tmp, all, 0);
//			}
//			tmp = tmp->next;
//		}
//		i++;
//	}
//	freeshka_str(str);
//}

static void	write_to_road(t_lem *lmn, t_lst *lst, t_lst *best)
{
	int		i;
	char 	*temp;
	t_lst	*tmp;
	char	*ping;

	i = best->iter;
	ping = best->prev;
	ROAD = (char **)malloc(sizeof(char *) * (i + 1));
	ROAD[i] = 0;
	i--;
	ROAD[i] = ft_strdup(best->room);
	i--;
	while (i >= 0)
	{
		tmp = lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, ping))
			{
				ROAD[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp->room) + 1));
				ROAD[i] = ft_strdup(tmp->room);
				if (tmp->prev)
					ping = tmp->prev;
				else
					return ;
				break ;
			}
			tmp = tmp->next;
		}
		i--;
	}
}

static void	write_road(t_lem *lmn, t_lst *lst, t_lst *all, int i)
{
	int 	c;
	char 	**str;
	t_lst	*tmp;
	t_lst	*best;
	int 	steps;

	steps = 0;
	str = ft_strsplit(LINKS, ' ');
	while (str[i] != 0)
	{
		tmp = all;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[i]) && tmp->iter
					&& (!steps || steps >= tmp->iter))
			{
				steps = tmp->iter;
				best = tmp;
			}
			tmp = tmp->next;
		}
		i++;
	}
	ft_printf("best: %s %d\n", best->room, best->iter);
	write_to_road(lmn, all, best);
	c = 0;
	while (ROAD[c] != 0)
	{
		ft_printf("%s\n", ROAD[c]);
		c++;
	}
}

void		algorithm(t_lem *lmn, t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
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
