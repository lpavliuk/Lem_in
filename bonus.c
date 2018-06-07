/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:04:02 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/07 15:04:04 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			show_color_road(t_road *start, t_lem *lmn)
{
	ft_printf("{blue}------------{yellow}The Quickest Way{blue}------------\n");
	ft_printf("{yellow}Start ");
	while (start)
	{
		if (!start->next)
			ft_printf("{yellow}End ");
		ft_printf("{blue}[%s] ", start->link->room);
		if (start->next)
			ft_printf("{yellow}--> ");
		start = start->next;
	}
	ft_printf("\n");
	ft_printf("----------------------------------------{eoc}\n");
	show_col_road(lmn);
}

void			bonus(char **argv)
{
	if (argv[2])
		ft_error(ERR_16);
	if (!ft_strcmp(argv[1], "-u") || !ft_strcmp(argv[1], "--usage"))
	{
		ft_printf("{yellow}Usage: {blue}./lem-in ");
		ft_printf("{pink}[option]{blue} < {red}[file map]\n");
		ft_printf("\n{blue}Use option ");
		ft_printf("{pink}[-o | --options] {blue}for see all options!\n");
		ft_error(NULL);
	}
	else if (!ft_strcmp(argv[1], "-o") || !ft_strcmp(argv[1], "--options"))
	{
		ft_printf("{pink}[options]:\n\n");
		ft_printf("{pink}-u | --usage     {blue}show programs usage\n");
		ft_printf("{pink}-o | --options   ");
		ft_printf("{blue}show all options for program\n");
		ft_printf("{pink}-l | --list      {blue}show list of rooms & links\n");
		ft_printf("{pink}-w | --way       {blue}show the quickest way\n");
		ft_error(NULL);
	}
	else if (!ft_strcmp(argv[1], "-w") || !ft_strcmp(argv[1], "--way"))
		return ;
	else
		ft_error(ERR_15);
}
