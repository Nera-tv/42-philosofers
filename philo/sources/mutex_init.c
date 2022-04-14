/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:13:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:55:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	mutex_init(t_table	*table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->philo_req.nbr_philo);
	if (!table->fork)
		return (write_error(table, ERRMEM));
	table->fork_state = malloc(sizeof(int) * table->philo_req.nbr_philo);
	if (!table->fork_state)
	{
		free(table->fork);
		return (write_error(table, ERRMEM));
	}
	memset(table->fork_state, 0, sizeof(int) * table->philo_req.nbr_philo);
	while (i < table->philo_req.nbr_philo)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->secu, NULL);
	return (0);
}
