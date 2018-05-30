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

static int 	digit_is(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		do_link(t_lst *lst, char *str)
{
	char	*tmp;

	if (LINKS)
	{
		if (ft_strstr(LINKS, str))
			return ;
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

void		write_link(t_lem *lmn, t_lst *lst)
{
	t_lst	*prev;
	t_lst	*tmp;
	char	**str;

	prev = lst;
	LINK++;
	str = ft_strsplit(LINE, '-');
	while (prev)
	{
		if (!ft_strcmp(prev->room, str[0]))
		{
			tmp = lst;
			while (tmp)
			{
				if (!ft_strcmp(tmp->room, str[1]))
				{
					do_link(prev, str[1]);
					do_link(tmp, str[0]);
					write_output(lmn, LINE);
					return ;
				}
				tmp = tmp->next;
			}
		}
		prev = prev->next;
	}
	ft_error(ERR_7);
}

void		write_room(t_lem *lmn, t_lst *lst)
{
	int		i;
	char	**str;

	i = 0;
	if (ROOM != NULL)
		lst = lstnew(lst);
	str = ft_strsplit(LINE, ' ');
	while (str[i] != 0)
	{
		if (i == 0)
			ROOM = ft_strdup(str[0]);
		else if (!digit_is(str[i]))
			ft_error(ERR_6);
		if (i == 1)
			X = ft_atoi(str[i]);
		else if (i == 2)
			Y = ft_atoi(str[i]);
		i++;
	}
	write_output(lmn, LINE);
	ft_stralldel(str, i);
	free(str);
}
