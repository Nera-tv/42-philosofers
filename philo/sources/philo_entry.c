/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:23 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:49:26 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_entry_o(void *a)
{
	t_philo	*p;
	t_table	*t;

	p = (t_philo *)a;
	t = (t_table *)p->ptable;
	p->time_b = timestamp();
	p->time_d = timestamp() + p->ptable->philo_req.t_die;
	pthread_mutex_lock(&p->ptable->fork[p->id]);
	printf("%llu %d has taken a fork\n", (timestamp() - p->time_b), p->id + 1);
	while (timestamp() < (p->time_d))
		usleep(25);
	printf("%llu %d %s\n", (timestamp() - p->time_b), p->id + 1, S_DIED);
	pthread_mutex_unlock(&p->ptable->fork[p->id]);
	return (0);
}

void	*philo_entry(void *a)
{
	t_philo	*p;
	t_table	*t;

	p = (t_philo *)a;
	t = (t_table *)p->ptable;
	p->time_b = timestamp();
	p->time_d = timestamp() + p->ptable->philo_req.t_die;
	if (p->id % 2 == 1)
		usleep(5000);
	while (1)
	{
		if (!eat(p))
			return (0);
		if (!action(p, 1, S_SLEEP, t->philo_req.t_sleep))
			return (0);
		p->st = 2;
		printf("%llu %d is %s\n", (timestamp() - p->time_b), p->id + 1, S_THINK);
	}
	return (0);
}
