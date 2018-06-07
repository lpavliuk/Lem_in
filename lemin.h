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

# define ERR_0 "{red}ERROR: {blue}incorrect number of {red}ants{blue}!\n"
# define ERR_1 "{red}ERROR: {blue}incorrect command {yellow}##start{blue}!\n"
# define ERR_2 "{red}ERROR: {blue}incorrect command {yellow}##end{blue}!\n"
# define ERR_3 "{red}ERROR: {blue}command {yellow}##start {blue}was repeated!\n"
# define ERR_4 "{red}ERROR: {blue}command {yellow}##end {blue}was repeated!\n"
# define ERR_6 "{red}ERROR: {blue}incorrect input {red}the room{blue}!\n"
# define ERR_7 "{red}ERROR: {blue}incorrect input {red}the link{blue}!\n"
# define ERR_8 "{red}ERROR: {blue}incorrect input data!\n"
# define ERR_9 "{red}ERROR: {blue}name for room is {red}repeating!\n"
# define ERR_10 "{red}ERROR: {blue}coordinates for room is {red}repeating!\n"
# define ERR_11 "{red}ERROR: {blue}incorrect input {red}the start room{blue}!\n"
# define ERR_12 "{red}ERROR: {blue}incorrect input {red}the end room{blue}!\n"
# define ERR_13 "{red}ERROR: {blue}links for room are {red}repeating!\n"
# define ERR_14 "{red}ERROR: {yellow}there isn't links between start & end!\n"
# define ERR_15 "{red}ERROR: {pink}undefined option, use '-o' for help!\n"
# define ERR_16 "{red}ERROR: {pink}option can be only ONE or '-l' with '-w'!\n"

# define ROOM lst->room
# define X lst->x
# define Y lst->y
# define NUMBER lst->number
# define WAS lst->was
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
# define L_ROAD lmn->links_road

typedef struct	s_lst
{
	char			*room;
	char			ant;
	char			*links;
	int				number;
	char			was;
	int				x;
	int				y;
	int				iter;
	char			str;
	char			en;
	char			*prev;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_road
{
	t_lst			*link;
	struct s_road	*prev;
	int				ant;
	struct s_road	*next;
}				t_road;

typedef struct	s_lem
{
	char	*line;
	char	start;
	char	end;
	char	link;
	char	*output;
	int		num_ants;
	t_road	*links_road;
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
void			algorithm(t_lem *lmn, t_lst *lst);
void			freeshka_str(char **str);
void			write_road(t_lem *lmn, t_lst *lst, t_lst *all, int i);
void			find_way(t_lem *lmn, t_lst *lst, t_lst *all);
void			show_road(t_lem *lmn);
void			do_link_prev(t_lem *lmn);
void			bonus(char **str);
void			show_color_road(t_road *start, t_lem *lmn);
void			show_col_road(t_lem *lmn);
void			show_list(t_lst *lst, t_lem *lmn);
void			check_flags(int argc, char **argv);

#endif
