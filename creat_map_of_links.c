/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_of_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:43:08 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/31 15:43:10 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_links(t_lem *lmn, t_lst *lst, char **str, int i)
{
	int		j;
	t_lst	*tmp;

	j = 0;
	while (str[j] != 0)
	{
		tmp = lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->room, str[j]))
			{
				MAP[i][tmp->number] = 1;
				break ;
			}
			tmp = tmp->next;
		}
		j++;
	}
}

static void	write_to_map(t_lem *lmn, t_lst *lst, int c, int i)
{
	int		j;
	t_lst	*tmp;
	char	**str;

	while (i < c)
	{
		tmp = lst;
		while (tmp)
		{
			j = 0;
			if (tmp->number == i)
			{
				if (tmp->links)
				{
					str = ft_strsplit(tmp->links, ' ');
					check_links(lmn, lst, str, i);
					while (str[j] != 0)
						free(str[j++]);
					free(str);
				}
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void		creat_map_of_links(t_lem *lmn, t_lst *lst, int i)
{
	int		c;
	t_lst	*tmp;

	tmp = lst;
	c = lstlen(lst);
	MAP = (char **)malloc(sizeof(char *) * (c + 1));
	while (i < c)
	{
		MAP[i] = (char *)malloc(sizeof(char) * (c + 1));
		ft_bzero(MAP[i], (size_t)c + 1);
		i++;
	}
	MAP[i] = 0;
	i = 1;
	while (lst)
	{
		if (STR == 1)
			NUMBER = 0;
		else if (EN == 1)
			NUMBER = c - 1;
		else
			NUMBER = i++;
		lst = NEXT;
	}
	write_to_map(lmn, tmp, c, 0);
}
