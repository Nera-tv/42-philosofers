/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:51:50 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:54:30 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	lock_fork2(t_philo *p, int which)
{
	int	f;
	int	state;

	f = (p->id + (which != 0)) % p->ptable->philo_req.nbr_philo;
	state = 0;
	pthread_mutex_lock(&p->ptable->fork[f]);
	if (p->ptable->fork_state[f] == 0)
	{
		p->ptable->fork_state[f] = p->id + 1;
		state = 1;
	}
	pthread_mutex_unlock(&p->ptable->fork[f]);
	return (state);
}

void	unlock_fork2(t_philo *p, int which)
{
	int	f;

	f = (p->id + (which != 0)) % p->ptable->philo_req.nbr_philo;
	pthread_mutex_lock(&p->ptable->fork[f]);
	if (p->ptable->fork_state[f] == p->id + 1)
	{
		p->ptable->fork_state[f] = 0;
	}
	pthread_mutex_unlock(&p->ptable->fork[f]);
}

void	lock_fork(t_philo *p)
{
	while (lock_fork2(p, 0) != 1)
	{
		usleep(ft_delay(p));
		if (timestamp() >= p->time_d || read_death(p) == 1)
			return (write_death(p));
	}
	printf("%llu %d has taken a fork\n", (timestamp() - p->time_b), p->id + 1);
	while (lock_fork2(p, 1) != 1)
	{
		usleep(ft_delay(p));
		if (timestamp() >= p->time_d || read_death(p) == 1)
		{
			unlock_fork2(p, 0);
			return (write_death(p));
		}
	}
	printf("%llu %d has taken a fork\n", (timestamp() - p->time_b), p->id + 1);
}

void	unlock_fork(t_philo *p)
{
	unlock_fork2(p, 0);
	unlock_fork2(p, 1);
}
