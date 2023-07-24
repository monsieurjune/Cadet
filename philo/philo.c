/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/21 20:34:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* AV list (ac : 4-5)
1: philo no
2: time to die
3: time to eat
4: time to sleep
5: (optional) end no
*/

static int	sb_init_or_des_mutex(t_mutex *locker, int destroy)
{
	if (destroy)
	{
		pthread_mutex_destroy(&locker->lock);
		pthread_mutex_destroy(&locker->grim);
		pthread_mutex_destroy(&locker->print);
		return (0);
	}
	if (pthread_mutex_init(&locker->grim, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&locker->lock, NULL) != 0)
	{
		pthread_mutex_destroy(&locker->grim);
		return (1);
	}
	if (pthread_mutex_init(&locker->print, NULL) != 0)
	{
		pthread_mutex_destroy(&locker->grim);
		pthread_mutex_destroy(&locker->lock);
		return (1);
	}
	return (0);
}

static int	sb_take_info(t_info	*data, t_mutex *locker, int ac, char **av)
{
	gettimeofday(&data->epoch, NULL);
	if (ac == 5)
		data->end_n = -1;
	else
		data->end_n = ft_philo_atoi(av[5]);
	data->philo_n = ft_philo_atoi(av[1]);
	data->die_ms = ft_philo_atoi(av[2]);
	data->eat_ms = ft_philo_atoi(av[3]);
	data->sleep_ms = ft_philo_atoi(av[4]);
	if (sb_init_or_des_mutex(locker, 0))
		return (1);
	if (data->end_n == 0 || data->philo_n == 0 || data->eat_ms == 0)
		return (1);
	return (data->die_ms == 0 || data->sleep_ms == 0);
}

static t_philo	*sb_init(t_info *data, t_mutex *lkr, int *who_die, char *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_n);
	if (philo == NULL)
		return (free(table), NULL);
	while (i < data->philo_n)
	{
		philo[i].i = i;
		philo->status = _first;
		philo[i].info = data;
		philo[i].life_ms = 0;
		philo[i].table = table;
		philo[i].who_die = who_die;
		philo[i].locker = lkr;
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	int		who_die;
	char	*table;
	t_info	data;
	t_philo	*philo;
	t_mutex	locker;

	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	if (sb_take_info(&data, &locker, ac, av))
		return (EXIT_FAILURE);
	table = malloc(sizeof(char) * data.philo_n);
	if (table == NULL)
		return (EXIT_FAILURE);
	who_die = -1;
	philo = sb_init(&data, &locker, &who_die, table);
	if (philo == NULL)
		return (EXIT_FAILURE);
	printf("%u, %u, %u\n", data.die_ms, data.eat_ms, data.sleep_ms);
	memset(table, 1, sizeof(char) * data.philo_n);
	if (data.philo_n % 2 == 0)
		ph_sim(philo, ph_run_even);
	free(philo);
	free(table);
	return (EXIT_SUCCESS);
}