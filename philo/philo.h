/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/08 18:52:34 by tponutha         ###   ########.fr       */
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

# ifndef DELAY_T
#  define DELAY_T 2000
# endif

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;

typedef struct	s_thd
{
	pthread_t	*tbox;
	int			n;
}	t_thd;

typedef struct	s_philo
{
	int				i;
	unsigned int	philo_no;
	unsigned int	die_t;
	unsigned int	eat_t;
	unsigned int	sleep_t;
	unsigned int	end_no;
	unsigned int	life_t;
	int				is_end;
	int				*no_die;
	char			*table;
}	t_philo;

/*		from libft		*/
int		ft_atoi(const char *str);
void	ph_sim(t_philo *philo);

#endif