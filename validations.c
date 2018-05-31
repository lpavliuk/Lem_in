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
		ft_error(ERR_0);
	while (LINE[i] != '\0')
	{
		if (!ft_isdigit(LINE[i]))
			ft_error(ERR_0);
		i++;
	}
	NUM_A = ft_atoi(LINE);
	write_output(lmn, LINE);
}

static void	comnt_or_comnd(t_lem *lmn, t_lst *lst, int i)
{
	if (NUM_A && LINE[i] == '#')
	{
		if (!ft_strcmp(LINE, "##start"))
		{
			if (START)
				ft_error(ERR_3);
			write_output(lmn, LINE);
			START++;
		}
		else if (!ft_strcmp(LINE, "##end"))
		{
			if (END)
				ft_error(ERR_4);
			write_output(lmn, LINE);
			END++;
		}
		else if (ft_strstr(LINE, "##start"))
			ft_error(ERR_1);
		else if (ft_strstr(LINE, "##end"))
			ft_error(ERR_2);
		else
			ft_error(ERR_5);
	}
	else if (!NUM_A && LINE[i] == '#')
		ft_error(ERR_0);
}

static int	check_room_or_link(t_lem *lmn, t_lst *lst, int i)
{
	int	def;
	int	space;

	def = 0;
	space = 0;
	while (LINE[i] != '\0')
	{
		if (LINE[i] == '-')
			def++;
		else if (LINE[i] == ' ')
			space++;
		i++;
	}
	if (!def && space == 2 && !LINK)
		write_room(lmn, lst);
	else if (!space && def == 1 && END && START)
		write_link(lmn, lst);
	else if (def && START && END)
		ft_error(ERR_7);
	else if (space && START && END)
		ft_error(ERR_6);
	else
		return (1);
	return (0);
}

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
		else if (check_room_or_link(lmn, lst, 0))
			ft_error(ERR_8);
		free(LINE);
		i++;
	}
}
