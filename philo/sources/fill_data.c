/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:49 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/11 14:26:04 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_philo(t_table *table, int n)
{
	if (table->philo_req.nbr_philo <= 0)
		write_error(table, ERRPHILO);
	if (table->philo_req.t_die <= 0)
		write_error(table, ERRTDIE);
	if (table->philo_req.t_eat <= 0)
		write_error(table, ERRTEAT);
	if (table->philo_req.t_sleep <= 0)
		write_error(table, ERRTSLEEP);
	if (table->philo_req.nbr_t_philos_eat <= 0 && n == 6)
		write_error(table, ERRTNTEATP);
}

int	fill_table(int nbr_of_arg, char *arg[], t_table *table)
{
	table->philo_req.nbr_philo = ft_atoi(arg[1]);
	table->philo_req.t_die = ft_atoi(arg[2]);
	table->philo_req.t_eat = ft_atoi(arg[3]);
	table->philo_req.t_sleep = ft_atoi(arg[4]);
	table->philo_req.nbr_t_philos_eat = INT_MAX;
	if (nbr_of_arg == 6)
		table->philo_req.nbr_t_philos_eat = ft_atoi(arg[5]);
	check_philo(table, nbr_of_arg);
	if (table->error > 0)
		return (1);
	return (0);
}
