/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:02:17 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/29 15:02:19 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(t_lem *lmn, char *error)
{
	free(LINE);
	free(lmn);
	ft_printf(error);
	exit(0);
}

int		main(void)
{
	t_lem *lmn;

	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	NUM_A = 0;
	START = 0;
	END = 0;
	check_input(lmn);
	return (0);
}
