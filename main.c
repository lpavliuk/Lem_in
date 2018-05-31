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
	while (lst)
	{
		ft_printf("room name: %s\n", ROOM);
		ft_printf("x: %d\ny: %d\n", X, Y);
		ft_printf("links: %s\n", LINKS);
		lst = NEXT;
	}
	ft_printf("start room: %s\n", STR);
	ft_printf("end room: %s\n", EN);
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

//static void	creat_map_of_links(t_lem *lmn, t_lst *lst)
//{
//
//}

int			main(void)
{
	t_lem *lmn;
	t_lst *lst;

	lst = malloc(sizeof(t_lst));
	ROOM = NULL;
	X = 0;
	Y = 0;
	ANT = 0;
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
	write_output(lmn, NULL);
	write_list(lst, lmn);
//	system("leaks lem-in");
	return (0);
}
