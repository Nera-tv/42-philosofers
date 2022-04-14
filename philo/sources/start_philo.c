/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:14:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:55:26 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_philo(t_table *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_req.nbr_philo)
	{
		t->ph[i].id = i;
		t->ph[i].ptable = t;
		t->ph[i].state = S_THINK;
		if (t->philo_req.nbr_philo == 1)
		{
			if (pthread_create(&t->ph[i].tid, NULL, &philo_entry_o, &t->ph[i]))
				return ;
		}
		else
		{
			if (pthread_create(&t->ph[i].tid, NULL, &philo_entry, &t->ph[i]))
				return ;
		}
	}
	i = -1;
	while (++i < t->philo_req.nbr_philo)
		pthread_join(t->ph[i].tid, NULL);
	i = -1;
	while (++i < t->philo_req.nbr_philo)
		pthread_mutex_destroy(&t->fork[i]);
}
