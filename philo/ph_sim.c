/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:47:33 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/08 18:53:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*sb_run(void *arg)
{
	int		n;
	t_philo	*philo;

	n = 0;
	philo = (t_philo *)arg;
	while (philo->no_die == 0)
	{
		if (n == 0)
			//
		
		n++;	
	}
	return (NULL);
}

static void	sb_mass_detach(t_thd info)
{
	int	i;

	i = 0;
	while (i < info.n)
	{
		pthread_detach(info.tbox[i]);
		i++;
	}
	free(info.tbox);
}

static void	sb_mass_create(t_philo *philo, t_thd *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (pthread_create(&info->tbox[i], NULL, sb_run, &philo[i]) != 0)
		{
			info->n = i;
			return ;
		}
		i++;
	}
}

void	ph_sim(t_philo *philo)
{
	t_thd			info;
	struct timeval	t_die;

	info.tbox = malloc(sizeof(pthread_t) * philo->philo_no);
	if (info.tbox == NULL)
		return ;
	sb_mass_create(philo, &info);
	sb_mass_detach(info);
	// 
}