/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:58:32 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/11 18:19:58 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	eat(t_philo *p)
{
	lock_fork(p);
	if (read_death(p) == 1)
	{
		unlock_fork(p);
		return (0);
	}
	if (!action(p, 0, S_EAT, p->ptable->philo_req.t_eat))
	{
		unlock_fork(p);
		return (0);
	}
	unlock_fork(p);
	return (1);
}
