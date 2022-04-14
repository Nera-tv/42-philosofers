/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:18:29 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:55:18 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_init(t_table *table)
{
	table->ph = malloc(sizeof(t_philo) * table->philo_req.nbr_philo);
	if (!table->ph)
		return (write_error(table, ERRMEM));
	memset(table->ph, 0, sizeof(t_philo) * table->philo_req.nbr_philo);
	start_philo(table);
	return (0);
}
