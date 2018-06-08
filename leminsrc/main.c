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
		ft_printf("\n");
	}
}

void		ft_error(char *error)
{
	ft_printf(error);
	exit(0);
}

void		first_step(t_lst *lst, t_lem *lmn)
{
	ROOM = NULL;
	NUMBER = 0;
	WAS = 0;
	X = 0;
	Y = 0;
	ANT = 0;
	STR = 0;
	EN = 0;
	ITER = 0;
	PREV = NULL;
	LINKS = NULL;
	NEXT = NULL;
	LINE = NULL;
	OUTPUT = NULL;
	NUM_A = 0;
	LINK = 0;
	START = 0;
	END = 0;
	L_ROAD = malloc(sizeof(t_road));
	L_ROAD->link = NULL;
	L_ROAD->prev = NULL;
	L_ROAD->ant = 0;
	L_ROAD->next = NULL;
}

int			main(int argc, char **argv)
{
	t_lem *lmn;
	t_lst *lst;

	lst = malloc(sizeof(t_lst));
	lmn = malloc(sizeof(t_lem));
	if (argc > 2)
		check_flags(argc, argv);
	if (argc > 1)
		bonus(argv);
	first_step(lst, lmn);
	check_input(lmn, lst);
	algorithm(lmn, lst);
	if (argc > 1 && (!ft_strcmp(argv[1], "-l")
			|| !ft_strcmp(argv[1], "--list") || (argv[2] &&
			(!ft_strcmp(argv[2], "-l") || !ft_strcmp(argv[2], "--list")))))
		show_list(lst, lmn);
	else
		write_output(lmn, NULL);
	if (argc > 1 && (!ft_strcmp(argv[1], "-w")
					|| !ft_strcmp(argv[1], "--way") || (argv[2] &&
			(!ft_strcmp(argv[2], "-w") || !ft_strcmp(argv[2], "--way")))))
		show_color_road(L_ROAD, lmn);
	else
		show_road(lmn);
	return (0);
}
