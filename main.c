/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:02:17 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/29 15:02:19 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	lst_del(t_lst **lst)
{
	t_lst	*ping;

	if (lst != NULL && *lst != NULL)
	{
		ping = *lst;
		while (ping)
		{
			free(ping->room);
			free(ping);
			ping = ping->next;
		}
		*lst = NULL;
	}
}

void		ft_error(t_lem *lmn, t_lst *lst, char *error)
{
	free(LINE);
	free(lmn);
	lst_del(&lst);
	ft_printf(error);
	exit(0);
}

int			main(void)
{
	t_lem *lmn;
	t_lst *lst;

	lst = malloc(sizeof(t_lst));
	ROOM = NULL;
	X = 0;
	Y = 0;
	NEXT = 0;
	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	NUM_A = 0;
	START = 0;
	END = 0;
	check_input(lmn, lst);
//	system("leaks lem-in");
	return (0);
}
