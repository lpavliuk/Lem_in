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

/************************************************
 *  CHECK LIST! DELETE IT LATER!
 ************************************************/
void		write_list(t_lst *lst)
{
	while (lst)
	{
		ft_printf("room name: %s\n", ROOM);
		ft_printf("x: %d\ny: %d\n", X, Y);
		lst = NEXT;
	}
}
/************************************************/

void		write_output(t_lem *lmn, char *str)
{
	char *tmp;

	if (str)
	{
		if (OUTPUT)
		{
			tmp = OUTPUT;
			OUTPUT = ft_strjoin(OUTPUT, str);
			free(tmp);
		}
		else
			OUTPUT = ft_strdup(str);
		tmp = OUTPUT;
		OUTPUT = ft_strjoin(OUTPUT, "\n");
		free(tmp);
	}
	else
		ft_printf(OUTPUT);
}

void		ft_error(char *error)
{
	ft_printf(error);
//	system("leaks lem-in");
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
	NEXT = NULL;
	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	OUTPUT = NULL;
	NUM_A = 0;
	START = 0;
	END = 0;
	LINK = 0;
	check_input(lmn, lst);
	write_output(lmn, NULL);
	write_list(lst);
//	system("leaks lem-in");
	return (0);
}
