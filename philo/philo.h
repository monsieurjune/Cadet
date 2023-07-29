/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/30 05:02:42 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# ifdef __linux
#  define _XOPEN_SOURCE 500
# endif
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

# ifndef DELAY_US
#  define DELAY_US 1
# endif

typedef struct timeval	t_time;

typedef enum e_stat
{
	_first,
	_take,
	_think,
	_idle,
	_eat,
	_sleep,
	_die
}	t_stat;

typedef struct s_info
{
	t_time			epoch;
	int				philo_n;
	int				end_n;
	unsigned int	die_ms;
	unsigned int	eat_ms;
	unsigned int	sleep_ms;
}	t_info;

typedef struct s_lock
{
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
	pthread_mutex_t	grim;
	pthread_mutex_t	age;
}	t_lock;

typedef struct s_philo
{
	int					i;
	int					eat_n;
	// int					odd_start;
	pthread_t			id;
	unsigned int		life_ms;
	const struct s_info	*info;
	struct s_lock		*locker;
	int					*who_die;
	char				*table;
}	t_philo;

/*		ph_sim.c		*/
void			ph_sim(t_philo *philo, int is_even);

/*		ph_act.c		*/
int				ph_delay(t_philo *phi, unsigned int t_max);
int				ph_get_fork(t_philo *phi);
int				ph_think(t_philo *phi);
int				ph_eat(t_philo *phi);
int				ph_sleep(t_philo *phi);

/*		ph_utils.c		*/
size_t			ft_strclen(const char *str, char c);
int				ft_philo_atoi(const char *str);

/*		ph_mutex.c		*/
void			ph_print_philo(t_philo *phi, t_time now, t_stat stat);
int				ph_check_die(t_philo *phi);
void			ph_aging(t_philo *philo);

/*		ph_time.c		*/
long			ph_timestamp(t_time now, t_time epoch);
t_time			ph_time_add(t_time t1, unsigned int delay_ms);
int				ph_is_time_exceed(t_time end);

#endif