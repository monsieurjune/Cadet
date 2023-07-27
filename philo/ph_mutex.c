/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/28 03:41:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_check_die(t_philo *phi)
{
	int	res;

	// pthread_mutex_lock(phi->info->lock);
	res = phi->who_die[0] != -1;
	// pthread_mutex_unlock(phi->info->lock);
	return (res);
}

/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

void	ph_print_philo(t_philo *phi, t_time now, t_stat stat)
{
	char	*str;
	long	ms;
	int		i;

	str = NULL;
	i = phi->i + 1;
	if (stat == _take)
		str = "has taken a fork";
	else if (stat == _think)
		str = "is thinking";
	else if (stat == _eat)
		str = "is eating";
	else if (stat == _sleep)
		str = "is sleeping";
	else if (stat == _die)
		str = "die";
	ms = ph_timestamp(now, phi->info->epoch);
	pthread_mutex_lock(&phi->locker->print);
	printf("\033[0;31m%ldms \033[0;32m%d \033[0;33m%s\n\033[0m", ms, i, str);
	pthread_mutex_unlock(&phi->locker->print);
}