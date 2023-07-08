/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:20:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/08 15:40:19 by tponutha         ###   ########.fr       */
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

typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}	t_mem;

typedef struct	s_philo
{
	unsigned int	die_t;
	unsigned int	eat_t;
	unsigned int	sleep_t;
	unsigned int	end_no;
	unsigned int	life_t;
	unsigned int	*no_die;
	char			*table;
}	t_philo;

/*		from libft		*/
int	ft_atoi(const char *str);

#endif