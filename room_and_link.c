/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_and_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:00:21 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/30 17:00:22 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	do_link(t_lst *lst, char *str)
{
	char	*tmp;

	if (LINKS)
	{
		if (ft_strstr(LINKS, str))
			ft_error(ERR_13);
		tmp = LINKS;
		LINKS = ft_strjoin(LINKS, str);
		free(tmp);
	}
	else
		LINKS = ft_strdup(str);
	tmp = LINKS;
	LINKS = ft_strjoin(LINKS, " ");
	free(tmp);
}

static int	while_tmp(t_lem *lmn, t_lst *prev, t_lst *tmp, char **str)
{
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, str[1]))
		{
			do_link(prev, str[1]);
			do_link(tmp, str[0]);
			write_output(lmn, LINE);
			ft_stralldel(str, 3);
			free(str);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		write_link(t_lem *lmn, t_lst *lst)
{
	t_lst	*prev;
	t_lst	*tmp;
	char	**str;

	prev = lst;
	LINK++;
	str = ft_strsplit(LINE, '-');
	if (!str[1])
		ft_error(ERR_7);
	while (prev)
	{
		if (!ft_strcmp(prev->room, str[0]))
		{
			tmp = lst;
			if (while_tmp(lmn, prev, tmp, str))
				return ;
		}
		prev = prev->next;
	}
	ft_error(ERR_7);
}

static void	while_str(t_lem *lmn, t_lst *lst, char **str, int i)
{
	if (i == 0)
	{
		ROOM = ft_strdup(str[0]);
		if ((int)STR == 1)
			STR = ROOM;
		if ((int)EN == 1)
			EN = ROOM;
	}
	else if (!digit_is(str[i]))
		ft_error(ERR_6);
	if (i == 1)
		X = ft_atoi(str[i]);
	else if (i == 2)
		Y = ft_atoi(str[i]);
}

void		write_room(t_lem *lmn, t_lst *lst)
{
	int		i;
	char	**str;
	t_lst	*all;

	i = 0;
	all = lst;
	if (ROOM != NULL)
		lst = lstnew(lst);
	str = ft_strsplit(LINE, ' ');
	while (str[i] != 0)
	{
		while_str(lmn, lst, str, i);
		i++;
	}
	check_room_in_list(all, lst);
	write_output(lmn, LINE);
	ft_stralldel(str, i);
	free(str);
}
