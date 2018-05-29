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

# define LINE lmn->line
# define COUNT lmn->count

typedef struct	s_lem
{
	char	*line;
	int 	count;
}				t_lem;

#endif