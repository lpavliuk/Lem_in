/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:03:17 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/29 15:03:19 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

# define ERR_0 "{red}Error: {blue}Wrong number of ants!\n"
# define ERR_1 "{red}Error: {blue}Wrong command {yellow}##start{blue}!\n"
# define ERR_2 "{red}Error: {blue}Wrong command {yellow}##end{blue}!\n"
# define ERR_3 "{red}Error: {blue}Command {yellow}##start {blue}was repeated!\n"
# define ERR_4 "{red}Error: {blue}Command {yellow}##end {blue}was repeated!\n"
# define ERR_5 "{red}Error: {blue}Command not found!\n"

# define LINE lmn->line
# define NUM_A lmn->num_ants
# define START lmn->start
# define END lmn->end

typedef struct	s_lem
{
	char	*line;
	int		num_ants;
	char	start;
	char	end;
}				t_lem;

#endif
