/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:24:58 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/20 22:15:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_check_die(t_philo *phi)
{
	int	res;

	pthread_mutex_lock(phi->info->lock);
	res = phi->who_die[0] != -1;
	pthread_mutex_unlock(phi->info->lock);
	return (res);
}

// int	ph_aging(t_philo *phi, int eat)
// {
// 	pthread_mutex_lock(phi->lock);
// 	if ()
// }