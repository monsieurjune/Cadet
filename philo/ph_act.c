/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:26:11 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/08 19:46:09 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
1.First check fork (use once)
2.Think & check fork
3.Eat & reset lift_t
4.Sleep

- All must check if someone really die
*/

int	ph_check_fork(t_philo *philo)
{
	t_mutex	lock;
	int		state;
	int		j;

	if (philo->no_die != 0)
		return (0);
	state = 0;
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_lock(&lock);
	if (philo->i == philo->philo_no - 1)
		j = 0;
	else
		j = philo->i + 1;
	if (philo->table[philo->i] == 1 && philo->table[j] == 1)
	{
		philo->table[j] = 0;
		philo->table[philo->i] = 0;
		state = 1;
	}
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
	return (state);
}

int	ph_think(t_philo *philo)
{

}

void	ph_eat(t_philo *philo)
{
	t_time			t1;
	unsigned int	mil;

	if (philo->no_die == 0)
	{
		gettimeofday(&t1, NULL);
		mil = t1.tv_sec * 1000 + t1.tv_usec / 1000;
		printf("%ums %d is eating\n", mil, philo->i);
		philo->life_t = 0;
		usleep(philo->sleep_t);
	}
}

void	ph_sleep(t_philo *philo)
{
	t_time			t1;
	unsigned int	mil;
	
	if (philo->no_die == 0)
	{
		gettimeofday(&t1, NULL);
		mil = t1.tv_sec * 1000 + t1.tv_usec / 1000;
		printf("%ums %d is sleeping\n", mil, philo->i);
		usleep(philo->sleep_t);
	}
}