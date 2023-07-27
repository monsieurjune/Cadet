/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:30:08 by tponutha          #+#    #+#             */
/*   Updated: 2023/07/28 03:41:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != 0 && str[len] != c)
		len++;
	return (len);
}

static int	sb_convert_number(const char *str)
{
	int	neg;
	int	sum;

	if (!str)
		return (0);
	sum = 0;
	neg = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	str += (*str == '+' || *str == '-');
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		if (sum < 0)
			return (-1);
		str++;
	}
	return (neg * sum);
}

int	ft_philo_atoi(const char *str)
{
	int	i;
	int	res;

	i = ft_strclen(str, 0);
	if (i > 10)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	res = sb_convert_number(str);
	if (res <= 0)
		return (0);
	return (res);
}

long	ph_timestamp(t_time now, t_time epoch)
{
	long	s;
	long	us;

	s = now.tv_sec - epoch.tv_sec;
	us = now.tv_usec - epoch.tv_usec;
	return (s * 1000 + us / 1000);
}
