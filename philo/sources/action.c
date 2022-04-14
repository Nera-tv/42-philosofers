/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:57:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:54:18 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	write_death(t_philo *p)
{
	pthread_mutex_lock(&p->ptable->secu);
	if (!p->ptable->s_dead)
	{
		p->ptable->s_dead = 1;
		printf("%llu %d %s\n", (timestamp() - p->time_b), p->id + 1, S_DIED);
	}
	pthread_mutex_unlock(&p->ptable->secu);
}

int	read_death(t_philo *p)
{
	pthread_mutex_lock(&p->ptable->secu);
	if (p->ptable->s_dead == 1)
	{
		pthread_mutex_unlock(&p->ptable->secu);
		return (1);
	}
	pthread_mutex_unlock(&p->ptable->secu);
	return (0);
}

int	ft_delay(t_philo *p)
{
	if (p->ptable->philo_req.nbr_philo < 10)
		return (25);
	else if (p->ptable->philo_req.nbr_philo < 100
		&& p->ptable->philo_req.nbr_philo >= 10)
		return (100);
	else if (p->ptable->philo_req.nbr_philo <= 300
		&& p->ptable->philo_req.nbr_philo >= 100)
		return (500);
	return (100);
}

int	action(t_philo *p, int st, char *statut, int t_)
{
	p->st = st;
	printf("%llu %d is %s\n", (timestamp() - p->time_b), p->id + 1, statut);
	p->_t = timestamp();
	if (st == 0 && ++p->nb_eat)
		p->time_d = timestamp() + p->ptable->philo_req.t_die;
	while (timestamp() < (p->_t + t_))
	{
		usleep(ft_delay(p));
		if (timestamp() >= (p->time_d))
		{
			write_death(p);
			return (0);
		}
		if (read_death(p) == 1)
			return (0);
	}
	return (!(p->nb_eat == p->ptable->philo_req.nbr_t_philos_eat));
}
