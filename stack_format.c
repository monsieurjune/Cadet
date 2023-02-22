/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:32:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/02/11 19:10:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
BIG NONO
1.) overflow
2.) non-int format
3.) dupicate
*/

static long sb_atol(char *str)
{
	int		i;
	long	neg;
	long	sum;

	i = 0;
	sum = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (str[i] == '-')
		neg = -1;
	str += (*str == '+' || *str == '-');
	while (str[i] >= '0' && str[i] <= '9' && i <= 10)
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sum > 2147483648 && neg == 1)
		return (2147483648);
	return (neg * sum);
}

// 0000000x is ok

static int	sb_check_format(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	i += (str[i] == '-' || str[i] == '+');
	//if (!(str[i] >= '0' && str[i] <= '9'))
	//	return (FALSE);
	//if (str[i] == '0' && str[i + 1] != '\0')
	//	return (FALSE);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (str[i - 1] >= '0' && str[i - 1] <= '9');
}

// ac = N
// av last pos = N - 1
// size = N - 1, ac - 1
// array last pos = N - 2
// Copy av to int array while maintain order

static int	*sb_atoi_array(int ac, char **av, t_listmem **head)
{
	long	temp;
	int		*res;
	int		i;

	res = lm_malloc(sizeof(int), ac - 1, head);
	if (res == NULL)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (!sb_check_format(av[i]))
			return (NULL);
		temp = sb_atol(av[i]);
		if (temp == 2147483648)
			return (NULL);
		res[i - 1] = (int)temp;
		i++;
	}
	return (res);
}

t_stack	*stack_check_array(int ac, char **av, t_listmem **head)
{
	int		*og;

	og = sb_atoi_array(ac, av, head);
	if (og == NULL)
		stack_exit(head);
	if(stack_isduplicate(og, ac - 1, head))
		stack_exit(head);
	return (stack_build(og, ac - 1, head));
}