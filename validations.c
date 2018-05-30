/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:00:56 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/30 14:00:59 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	only_digits(t_lem *lmn, t_lst *lst)
{
	int i;

	i = 0;
	if (LINE[0] == '\0')
		ft_error(lmn, lst, ERR_0);
	while (LINE[i] != '\0')
	{
		if (!ft_isdigit(LINE[i]))
			ft_error(lmn, lst, ERR_0);
		i++;
	}
	NUM_A = ft_atoi(LINE);
	ft_printf("%d\n", NUM_A);
}

static void	comnt_or_comnd(t_lem *lmn, t_lst *lst, int i)
{
	if (NUM_A && LINE[i] == '#')
	{
		if (!ft_strcmp(LINE, "##start"))
		{
			if (START)
				ft_error(lmn, lst, ERR_3);
			ft_printf("%s\n", LINE);
			START++;
		}
		else if (!ft_strcmp(LINE, "##end"))
		{
			if (END)
				ft_error(lmn, lst, ERR_4);
			ft_printf("%s\n", LINE);
			END++;
		}
		else if (ft_strstr(LINE, "##start"))
			ft_error(lmn, lst, ERR_1);
		else if (ft_strstr(LINE, "##end"))
			ft_error(lmn, lst, ERR_2);
		else
			ft_error(lmn, lst, ERR_5);
	}
	else if (!NUM_A && LINE[i] == '#')
		ft_error(lmn, lst, ERR_0);
}

//static void	check_room()

void		check_input(t_lem *lmn, t_lst *lst)
{
	int i;

	i = 0;
	while (get_next_line(0, &LINE) > 0)
	{
		if (!NUM_A && LINE[0] != '#')
			only_digits(lmn, lst);
		else if (LINE[0] == '#')
			comnt_or_comnd(lmn, lst, 1);
//		else if (check_room(lmn))
//			ft_error(lmn, lst, ERR_6);

		free(LINE);
		i++;
	}
}
