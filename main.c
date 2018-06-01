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
void		write_list(t_lst *lst, t_lem *lmn)
{
	t_lst *tmp;

	tmp = lst;
	while (lst)
	{
		if (STR)
			ft_printf("START!\n");
		if (EN)
			ft_printf("END!\n");
		ft_printf("---------[%s]--------\n", ROOM);
//		ft_printf("N: %d\n", NUMBER);
//		ft_printf("x: %d\ny: %d\n", X, Y);
		if (STR)
			ft_printf("start: %d\n", STR);
		if (EN)
			ft_printf("end: %d\n", EN);
		ft_printf("prev room: %s\n", PREV);
		ft_printf("iter: %d\n", ITER);
		if (LINKS)
			ft_printf("links: %s\n", LINKS);
		else
			ft_printf("links: (null)\n");
		ft_printf("-----------------------------------\n");
		lst = NEXT;
	}
}
/************************************************/

int			digit_is(char *str)
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
	NUMBER = 0;
	X = 0;
	Y = 0;
	ANT = 0;
	STR = 0;
	EN = 0;
	ITER = 0;
	PREV = NULL;
	LINKS = NULL;
	NEXT = NULL;
	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	OUTPUT = NULL;
	NUM_A = 0;
	LINK = 0;
	START = 0;
	END = 0;
	ROAD = 0;
//	COUNT = 0;
	check_input(lmn, lst);
//	creat_map_of_links(lmn, lst, 0);
	algorithm(lmn, lst);
//	write_output(lmn, NULL);
	ft_printf("-------------------------------------------------------------\n"); //DELETE IT!
	write_list(lst, lmn);
//	system("leaks lem-in");
	return (0);
}
