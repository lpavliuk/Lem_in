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
void		write_map(t_lem *lmn, t_lst *lst)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = lstlen(lst);
	ft_printf("   ");
	while (j < c)
		ft_printf("%-2d", j++);
	ft_printf("\n");
	ft_printf("   ");
	j = 0;
	while (j < c)
		ft_printf("- ", j++);
	ft_printf("\n");
	while (MAP[i] != 0)
	{
		j = 0;
		ft_printf("%i |", i);
		while (j < c)
			ft_printf("%-2d", MAP[i][j++]);
		ft_printf("\n");
		i++;
	}
}
void		write_list(t_lst *lst, t_lem *lmn)
{
	t_lst *tmp;

	tmp = lst;
	while (lst)
	{
		ft_printf("room name: %s\n", ROOM);
		ft_printf("N: %d\n", NUMBER);
		ft_printf("x: %d\ny: %d\n", X, Y);
		if (LINKS)
			ft_printf("links: %s\n", LINKS);
		else
			ft_printf("links: (null)\n");
		lst = NEXT;
	}
	ft_printf("start room: %s\n", STR);
	ft_printf("end room: %s\n", EN);
	write_map(lmn, tmp);
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
	{
		ft_printf(OUTPUT);
		ft_printf("-----------------------------------\n"); //DELETE IT!
	}
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
	ITER = 0;
	PREV = NULL;
	LINKS = NULL;
	NEXT = NULL;
	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	OUTPUT = NULL;
	NUM_A = 0;
	START = 0;
	END = 0;
	LINK = 0;
	STR = 0;
	EN = 0;
	MAP = NULL;
	check_input(lmn, lst);
	creat_map_of_links(lmn, lst, 0);
	write_output(lmn, NULL);
	write_list(lst, lmn);
//	system("leaks lem-in");
	return (0);
}
