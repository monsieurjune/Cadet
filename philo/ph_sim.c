/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:47:33 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/28 03:44:07 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* EVEN
1.) odd-th philo start eat first
	- odd-th philo call mutex on table
	- even-th philo start thinking & idle
	- odd-th philo start sleeping & return fork
2.) even-th philo start eating after odd-th philo sleep
	- even-th philo call mutex on table
	- even-th philo start sleeping & return fork
	- odd-th philo wake up & thinking ~1ms
		- if there is enough fork on table then eat again
		- else idle until there is fork
*/

void	*ph_run_even(void *arg)
{
	t_philo	*phi;
	int		success;

	phi = (t_philo *)arg;
	success = 0;
	if (phi->i % 2 == 0)
		success = ph_get_fork(phi);
	while (success != -1)
	{
		if (success)
		{
			if (ph_eat(phi) == -1)
				break ;
			if (ph_sleep(phi) == -1)
				break ;
		}
		success = ph_think(phi);
	}
	return (NULL);
}

void	ph_sim(t_philo *philo, int is_even)
{
	static int		i = 0;
	static int		j = 0;

	if (is_even)
	{
		while (i < philo->info->philo_n)
		{
			if (pthread_create(&philo->id, NULL, ph_run_even, &philo[i]) != 0)
				break ;
			i++;
		}
	}
	else
	{
		while (i < philo->info->philo_n)
		{
			if (pthread_create(&philo->id, NULL, ph_run_even, &philo[i]) != 0)
				break ;
			i++;
		}
	}
	while (j < i)
	{
		pthread_join(philo->id, NULL);
		j++;
	}
}