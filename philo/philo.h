/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/06 21:58:13 by tponutha         ###   ########.fr       */
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
# include <stdint.h>

typedef pthread_mutex_t	t_mutex;

typedef struct	s_philo
{
	uint32_t	life_t;
	uint32_t	die_t;
	uint32_t	eat_t;
	uint32_t	sleep_t;
	char		*table;
}	t_philo;

#endif