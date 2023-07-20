/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/20 22:17:45 by tponutha         ###   ########.fr       */
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

static int	sb_take_info(t_info	*data, t_mutex *lock, int ac, char **av)
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
	if (pthread_mutex_init(lock, NULL) != 0)
		return (1);
	data->lock = lock;
	if (data->end_n == 0 || data->philo_n == 0 || data->eat_ms == 0)
		return (1);
	return (data->die_ms == 0 || data->sleep_ms == 0);
}

static t_philo	*sb_init(t_info *data, int *who_die, char *table)
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
	t_mutex	lock;

	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	if (sb_take_info(&data, &lock, ac, av))
		return (EXIT_FAILURE);
	table = malloc(sizeof(char) * data.philo_n);
	if (table == NULL)
		return (EXIT_FAILURE);
	who_die = -1;
	philo = sb_init(&data, &who_die, table);
	if (philo == NULL)
		return (EXIT_FAILURE);
	memset(table, 1, sizeof(char) * data.philo_n);
	if (data.philo_n % 2 == 0)
		ph_sim(philo, ph_run_even);
	pthread_mutex_destroy(&lock);
	free(philo);
	free(table);
	return (EXIT_SUCCESS);
}