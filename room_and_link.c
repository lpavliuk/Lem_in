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
		{
			ft_stralldel(str, i);
			free(str);
			ft_error(ERR_6);
		}
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
