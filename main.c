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

void	ft_error(t_lem *lmn, char *error)
{
	free(LINE);
	free(lmn);
	ft_printf(error);
	exit(0);
}

void 	only_digits(t_lem *lmn)
{
	int i;

	i = 0;
	if (LINE[0] == '\0')
		ft_error(lmn, ERR_0);
	while (LINE[i] != '\0')
	{
		if (!ft_isdigit(LINE[i]))
			ft_error(lmn, ERR_0);
		i++;
	}
	NUM_A = ft_atoi(LINE);
}

void 	comnt_or_comnd(t_lem *lmn)
{
	int		i;

	i = 1;
	if (LINE[i] == '#')
	{
		if (!ft_strcmp(LINE, "##start"))
		{
			if (START)
				ft_error(lmn, ERR_3);
			START++;
		}
		else if (!ft_strcmp(LINE, "##end"))
		{
			if (END)
				ft_error(lmn, ERR_4);
			END++;
		}
		else if (ft_strstr(LINE, "##start"))
			ft_error(lmn, ERR_1);
		else if (ft_strstr(LINE, "##end"))
			ft_error(lmn, ERR_2);
		else
			ft_error(lmn, ERR_5);
	}
}

void	check_input(t_lem *lmn)
{
	int i;

	i = 0;
	while (get_next_line(0, &LINE) > 0)
	{
		if (i == 0)
			only_digits(lmn);
		else if (LINE[0] == '#')
			comnt_or_comnd(lmn);
//		if (is_it_a_room)
		printf("count: %d\n", NUM_A);
		free(LINE);
		i++;
	}
}

int		main(void)
{
	t_lem *lmn;

	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	NUM_A = 0;
	START = 0;
	END = 0;

	check_input(lmn);
	return (0);
}
