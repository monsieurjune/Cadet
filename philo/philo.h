/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/24 20:23:07 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

# ifndef DELAY_T
#  define DELAY_T 50
# endif

typedef struct timeval	t_time;

typedef enum	e_stat
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
}	t_lock;

typedef struct s_philo
{
	int					i;
	t_stat				status;
	pthread_t			id;
	unsigned int		life_ms;
	const struct s_info	*info;
	struct s_lock		*locker;
	int					*who_die;
	char				*table;
}	t_philo;


/*		LIBFT'ISH THING		*/
int				ft_philo_atoi(const char *str);

/*		PHILO THING			*/

/*		ph_sim.c		*/
void			ph_sim(t_philo *philo, void *f(void *));
void			*ph_run_even(void *arg);

/*		ph_act.c		*/
int				ph_delay(t_philo *phi, unsigned int t_max);
int				ph_get_fork(t_philo *phi);
int				ph_think(t_philo *phi);
int				ph_eat(t_philo *phi);
int				ph_sleep(t_philo *phi);

/*		ph_utils.c		*/
size_t			ft_strclen(const char *str, char c);
long			ph_timestamp(t_time now, t_time epoch);
void			ph_print_philo(int i, t_stat stat, t_time now, t_time epoch);
int				ph_check_die(t_philo *phi);

#endif