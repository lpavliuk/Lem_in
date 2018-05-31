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

# define ERR_0 "{red}Error: {blue}wrong number of {red}ants{blue}!\n"
# define ERR_1 "{red}Error: {blue}wrong command {yellow}##start{blue}!\n"
# define ERR_2 "{red}Error: {blue}wrong command {yellow}##end{blue}!\n"
# define ERR_3 "{red}Error: {blue}command {yellow}##start {blue}was repeated!\n"
# define ERR_4 "{red}Error: {blue}command {yellow}##end {blue}was repeated!\n"
# define ERR_5 "{red}Error: {blue}command not found!\n"
# define ERR_6 "{red}Error: {blue}incorrect input {red}the room{blue}!\n"
# define ERR_7 "{red}Error: {blue}incorrect input {red}the link{blue}!\n"
# define ERR_8 "{red}Error: {blue}incorrect input!\n"
# define ERR_9 "{red}Error: {blue}name for room is {red}repeating!\n"
# define ERR_10 "{red}Error: {blue}coordinates for room is {red}repeating!\n"
# define ERR_11 "{red}Error: {blue}incorrect input {red}the start room{blue}!\n"
# define ERR_12 "{red}Error: {blue}incorrect input {red}the end room{blue}!\n"
# define ERR_13 "{red}Error: {blue}links for room is {red}repeating!\n"

# define ROOM lst->room
# define X lst->x
# define Y lst->y
# define ANT lst->ant
# define LINKS lst->links
# define NEXT lst->next

# define LINE lmn->line
# define OUTPUT lmn->output
# define NUM_A lmn->num_ants
# define START lmn->start
# define END lmn->end
# define LINK lmn->link
# define STR lmn->st
# define EN lmn->en
# define MAP lmn->map

typedef struct	s_lst
{
	char			*room;
	int				x;
	int				y;
	char 			ant;
	char			*links;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_lem
{
	char	*line;
	int		num_ants;
	char	start;
	char	end;
	char	link;
	char	*output;
	char	*st;
	char	*en;
	char 	**map;
}				t_lem;

void			ft_error(char *error);
int				digit_is(char *str);
void			check_input(t_lem *lmn, t_lst *lst);
void			write_output(t_lem *lmn, char *str);
void			write_room(t_lem *lmn, t_lst *lst);
void			write_link(t_lem *lmn, t_lst *lst);
t_lst			*lstnew(t_lst *lst);
void			check_room_in_list(t_lst *lst, t_lst *new);
int				check_room_or_link(t_lem *lmn, t_lst *lst, int i);

#endif
