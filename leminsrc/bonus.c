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

void		check_flags(int argc, char **argv)
{
	if (argc > 3 || (argv[2] && ft_strcmp(argv[2], "-w") &&
			ft_strcmp(argv[2], "--way") && ft_strcmp(argv[2], "-l")
			&& ft_strcmp(argv[2], "--list")))
		ft_error(ERR_16);
}

void		show_list(t_lst *lst, t_lem *lmn)
{
	ft_printf("{blue}-------------{yellow}NUMBER OF ANTS{blue}------------\n");
	ft_printf("{blue}Ants:{red} %d\n", NUM_A);
	ft_printf("{blue}-------------{yellow}ROOMS & LINKS{blue}-------------\n");
	while (lst)
	{
		if (STR)
			ft_printf("{pink}START!\n");
		else if (EN)
			ft_printf("{pink}END!\n");
		ft_printf("{blue}Room name:{red} ");
		ft_printf("%s\n", ROOM);
		ft_printf("{yellow}links:{red} ");
		if (LINKS)
			ft_printf("%s\n", LINKS);
		else
			ft_printf("(null)\n");
		lst = NEXT;
		ft_printf("{blue}----------------------------------------{eoc}\n\n");
	}
}

void		show_color_road(t_road *start, t_lem *lmn)
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

static void	show_usage(void)
{
	ft_printf("{yellow}Usage: {blue}./lem-in ");
	ft_printf("{pink}[option]{blue} < {red}[file].txt\n");
	ft_printf("\n{blue}Use option ");
	ft_printf("{pink}[-o | --options] {blue}for see all options!\n\n");
	ft_printf("{red}File must consists of: \n");
	ft_printf("{red}1: {blue}number_of_ants ");
	ft_printf("{yellow}(only positive digits)\n");
	ft_printf("{red}2: {blue}the_rooms ");
	ft_printf("{yellow}(name of room & coordinates can't repeat)\n");
	ft_printf("{red}3: {blue}the_links ");
	ft_printf("{yellow}(links can't repeat)\n");
	ft_error(NULL);
}

void		bonus(char **argv)
{
	if (!ft_strcmp(argv[1], "-u") || !ft_strcmp(argv[1], "--usage"))
		show_usage();
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
	else if (!ft_strcmp(argv[1], "-l") || !ft_strcmp(argv[1], "--list"))
		return ;
	else
		ft_error(ERR_15);
}
