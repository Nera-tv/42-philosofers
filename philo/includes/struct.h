/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:34:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/13 13:48:38 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define S_SLEEP "sleeping"
# define S_EAT "eating"
# define S_THINK "thinking"
# define S_DIED "died"

typedef struct s_philo_req	t_philo_req;
typedef struct s_table		t_table;
typedef struct s_philo		t_philo;

struct s_philo_req
{
	int	nbr_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nbr_t_philos_eat;
};

struct s_philo
{
	t_table		*ptable;
	pthread_t	tid;
	int			id;
	char		*state;
	int			st;
	int			nb_eat;
	uint64_t	time_b;
	uint64_t	time_d;
	uint64_t	_t;
};

struct s_table
{
	t_philo			*ph;
	pthread_mutex_t	*fork;
	int				*fork_state;
	pthread_mutex_t	secu;
	t_philo_req		philo_req;
	int				s_dead;
	int				error;
};

#endif