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

static void	start_and_end(t_lem *lmn, t_lst *lst, char st)
{
	if (st)
	{
		if (START)
			ft_error(ERR_3);
		write_output(lmn, LINE);
		free(LINE);
		if (get_next_line(0, &LINE) == 0 && LINE[0] == '\0')
			ft_error(ERR_11);
		if (++START && check_room_or_link(lmn, lst, 0))
			ft_error(ERR_11);
	}
	else
	{
		if (END)
			ft_error(ERR_4);
		write_output(lmn, LINE);
		free(LINE);
		if (get_next_line(0, &LINE) == 0 && LINE[0] == '\0')
			ft_error(ERR_12);
		if (++END && check_room_or_link(lmn, lst, 0))
			ft_error(ERR_12);
	}
}

static void	comnt_or_comnd(t_lem *lmn, t_lst *lst, int i)
{
	if (NUM_A && LINE[i] == '#')
	{
		if (!ft_strcmp(LINE, "##start"))
			start_and_end(lmn, lst, 1);
		else if (!ft_strcmp(LINE, "##end"))
			start_and_end(lmn, lst, 0);
		else if (ft_strstr(LINE, "##start"))
			ft_error(ERR_1);
		else if (ft_strstr(LINE, "##end"))
			ft_error(ERR_2);
		else if (LINE[i + 1] == '#')
			ft_error(ERR_8);
		else
			write_output(lmn, LINE);
	}
	else
		write_output(lmn, LINE);
}

int			check_room_or_link(t_lem *lmn, t_lst *lst, int i)
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
	if (!def && space == 2 && !LINK && LINE[0] != 'L')
		write_room(lmn, lst);
	else if (!space && def == 1 && END && START)
		write_link(lmn, lst);
	else if (def && START && END && !LINK)
		ft_error(ERR_7);
	else if (space && START && END)
		ft_error(ERR_6);
	else
		return (1);
	return (0);
}

void		check_input(t_lem *lmn, t_lst *lst)
{
	while (get_next_line(0, &LINE) > 0)
	{
		if (!NUM_A && LINE[0] != '#')
			only_digits(lmn, lst);
		else if (LINE[0] == '#')
			comnt_or_comnd(lmn, lst, 1);
		else if (check_room_or_link(lmn, lst, 0))
		{
			free(LINE);
			break ;
		}
		free(LINE);
	}
	if (!LINK)
		ft_error(ERR_8);
}
