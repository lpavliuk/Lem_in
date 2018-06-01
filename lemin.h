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
# define NUMBER lst->number
# define ANT lst->ant
# define ITER lst->iter
# define PREV lst->prev
# define LINKS lst->links
# define NEXT lst->next
# define EN lst->en
# define STR lst->str

# define LINE lmn->line
# define OUTPUT lmn->output
# define NUM_A lmn->num_ants
# define START lmn->start
# define END lmn->end
# define LINK lmn->link

typedef struct	s_lst
{
	char			*room;
	char			ant;
	char			*links;
	int				number;
	int				x;
	int				y;
	int 			iter;
	char			str;
	char			en;
	char 			*prev;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_lem
{
	char	*line;
	char	start;
	char	end;
	char	link;
	char	*output;
	int		num_ants;
}				t_lem;

void			ft_error(char *error);
int				digit_is(char *str);
void			check_input(t_lem *lmn, t_lst *lst);
void			write_output(t_lem *lmn, char *str);
void			write_room(t_lem *lmn, t_lst *lst);
void			write_link(t_lem *lmn, t_lst *lst);
t_lst			*lstnew(t_lst *lst);
int				lstlen(t_lst *lst);
void			check_room_in_list(t_lst *lst, t_lst *new);
int				check_room_or_link(t_lem *lmn, t_lst *lst, int i);
void			creat_map_of_links(t_lem *lmn, t_lst *lst, int i);
void			algorithm(t_lem *lmn, t_lst *lst);
void			freeshka_str(char **str);

#endif
