/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/08 19:30:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sb_ms_to_us(int n)
{
	int	tmp;

	tmp = n;
	n *= 1000;
	if (tmp > n)
		return (0);
	return (n);
}

static int	sb_convert_number(char *arg)
{
	int	i;
	int	res;

	i = 0;
	while (arg[i] != 0)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	res = ft_atoi(arg);
	if (res <= 0)
		return (0);
	return (res);
}

/* AV list (ac : 4-5)
1: philo no
2: time to die
3: time to eat
4: time to sleep
5: (optional) end no
*/

static int	sb_sample(int ac, char **av, int *no_die, t_philo *sample)
{
	int	philo_no;

	sample->no_die = no_die;
	philo_no = sb_convert_number(av[1]);
	sample->die_t = sb_ms_to_us(sb_convert_number(av[2]));
	sample->eat_t = sb_ms_to_us(sb_convert_number(av[3]));
	sample->sleep_t = sb_ms_to_us(sb_convert_number(av[4]));
	sample->is_end = (ac == 6);
	if (sample->is_end)
		sample->end_no = sb_convert_number(av[5]);
	else
		sample->end_no = 0;
	if (philo_no <= 0 || sample->die_t <= 0 || sample->eat_t <= 0)
		return (0);
	if (sample->is_end && sample->end_no <= 0)
		return (0);
	sample->philo_no = philo_no;
	return (sample->sleep_t >= 0);
}

static t_philo	*sb_philo_init(t_philo sample, char *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * sample.philo_no);
	if (philo == NULL)
		return (free(table), NULL);
	while (i < sample.philo_no)
	{
		philo[i].i = i;
		philo[i].philo_no = sample.philo_no;
		philo[i].die_t = sample.die_t;
		philo[i].eat_t = sample.eat_t;
		philo[i].end_no = sample.end_no;
		philo[i].is_end = sample.is_end;
		philo[i].life_t = sample.life_t;
		philo[i].sleep_t = sample.sleep_t;
		philo[i].table = table;
		philo[i].no_die = sample.no_die;
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_philo	sample;
	t_philo	*philo;
	char	*table;
	int		no_die;
	
	no_die = 0;
	if (ac > 6 || ac < 5)
		return (EXIT_SUCCESS);
	if (sb_sample(ac, av, &no_die, &sample))
		return (EXIT_SUCCESS);
	table = malloc(sizeof(char *) * sample.philo_no);
	if (table == NULL)
		return (EXIT_FAILURE);
	memset(table, 1, sizeof(char *) * sample.philo_no);
	philo = sb_philo_init(sample, table);
	if (philo == NULL)
		return (EXIT_FAILURE);
	ph_sim(philo);
	free(philo);
	free(table);
	return (EXIT_SUCCESS);
}