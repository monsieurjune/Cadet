/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:50:43 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/15 23:09:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NOTE : when overflow value will be negative

int	ft_atoi(const char *str)
{
	long	neg;
	long	sum;

	if (!str)
		return (0);
	sum = 0;
	neg = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	str += (*str == '+' || *str == '-');
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		if (sum < 0)
			return (-1 * (neg != -1));
		str++;
	}
	return (neg * sum);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("STD : %d\n", atoi(av[1]));
	printf("USR : %d\n", ft_atoi(av[1]));
	return (0);
}
*/