/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:39:56 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:53:58 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "error_msg.h"
# include "struct.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

int			fill_table(int nbr_of_arg, char *arg[], t_table *table);
int			ft_atoi(const char *nptr);
int			write_error(t_table *table, char *msg);
int			action(t_philo *p, int st, char *statut, int t_);
int			eat(t_philo *p);
int			mutex_init(t_table	*table);
int			philo_init(t_table *table);
int			read_death(t_philo *p);
int			ft_delay(t_philo *p);
void		write_death(t_philo *p);
void		*philo_entry(void *a);
void		*philo_entry_o(void *a);
void		print_error(t_table *table, char *msg);
void		lock_fork(t_philo *p);
void		unlock_fork(t_philo *p);
void		start_philo(t_table *table);
uint64_t	timestamp(void);

#endif