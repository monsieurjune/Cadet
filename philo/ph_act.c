/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:26:11 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/21 20:01:02 by tponutha         ###   ########.fr       */
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

int	ph_delay(t_philo *phi, unsigned int t_max_ms)
{
	unsigned int	t_ms;
	unsigned int	t_us;

	t_ms = 0;
	while (t_ms < t_max_ms)
	{
		t_us = 0;
		while (t_us < 1000)
		{
			if (ph_check_die(phi))
				return (-1);
			usleep(DELAY_T);
			t_us += DELAY_T;
		}
		t_ms++;
	}
	return (1);
}

int	ph_get_fork(t_philo *phi)
{
	int	get_fork;
	int	i;
	int	j;

	if (ph_check_die(phi))
		return (-1);
	i = phi->i;
	j = i + 1;
	j = j * (j != phi->info->philo_n);
	pthread_mutex_lock(phi->info->lock);
	get_fork = (phi->table[i] == 1 && phi->table[j] == 1 && i != j);
	if (get_fork)
	{
		phi->table[i] = 0;
		phi->table[j] = 0;
		ph_print_philo(phi->i, _take, phi->info->epoch);
	}
	pthread_mutex_unlock(phi->info->lock);
	return (get_fork);
}

// it will stop only when it got fork or die

int	ph_think(t_philo *phi)
{
	if (ph_check_die(phi))
		return (-1);
	ph_print_philo(phi->i, _think, phi->info->epoch);
	while (1)
	{
		if (ph_delay(phi, 1) == -1)
			return (-1);
		if (ph_get_fork(phi))
			break ;
	}
	return (1);
}

// if (phi->table[i] == 1 && phi->table[j] == 1)
// 		printf("Data Race Here dude");

int	ph_eat(t_philo *phi)
{
	int	j;

	j = phi->i + 1;
	j = j * (j != phi->info->philo_n);
	if (ph_check_die(phi))
		return (-1);
	pthread_mutex_lock(phi->locker->grim);
	phi->life_ms = 0;
	pthread_mutex_unlock(phi->info->lock);
	ph_print_philo(phi->i, _eat, phi->info->epoch);
	if (ph_delay(phi, phi->info->eat_ms) == -1)
		return (-1);
	pthread_mutex_lock(phi->info->lock);
	phi->table[phi->i] = 1;
	phi->table[j] = 1;
	pthread_mutex_unlock(phi->info->lock);
	return (1);
}

int	ph_sleep(t_philo *phi)
{
	if (ph_check_die(phi))
		return (-1);
	ph_print_philo(phi->i, _sleep, phi->info->epoch);
	return (ph_delay(phi, phi->info->sleep_ms));
}