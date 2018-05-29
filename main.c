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

int 	only_digits(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	say_error(t_lem *lmn)
{
	free(LINE);
	free(lmn);
	ft_printf("Error!\n");
	exit(0);
}

void	check_input(t_lem *lmn)
{
	while (get_next_line(0, &LINE) > 0)
	{
		if (only_digits(LINE))
			say_error(lmn);
		COUNT = ft_atoi(LINE);
		printf("count: %d\n", COUNT);
		free(LINE);
	}
}

int		main(void)
{
	t_lem *lmn;

	lmn = malloc(sizeof(t_lem));
	LINE = NULL;
	COUNT = 0;

	check_input(lmn);
	return (0);
}
