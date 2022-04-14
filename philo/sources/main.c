/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:35:05 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:52:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_return(t_table *t, int ret)
{
	free(t->fork_state);
	free(t->fork);
	free(t->ph);
	free(t);
	return (ret);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc < 5 || argc > 6)
		return (write_error(&table, ERRARG));
	if (fill_table(argc, argv, &table) == 1)
		return (ft_return(&table, 1));
	if (mutex_init(&table) == 1)
		return (ft_return(&table, 1));
	if (philo_init(&table) == 1)
		return (ft_return(&table, 1));
	return (ft_return(&table, 0));
}
