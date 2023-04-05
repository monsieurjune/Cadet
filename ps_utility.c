/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:36:47 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/06 00:54:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ps_bottom_index(t_stack a, int bottom)
{
    int	i;

	i = 0;
	if (a.head == NULL)
		return (-1);
	while (a.head != a.tail && a.head->prev != a.tail)
	{
		if (a.head->value == bottom)
			return (i);
		a.head = a.head->next;
		if (a.tail->value == bottom)
			return (a.n - i - 1);
		a.tail = a.tail->prev;
		i++;
	}
	if (a.head->value == bottom)
		return (i);
	return (-1);
}

int	ps_node_depth(t_stack stack, int find)
{
	int	i;

	i = 1;
	while (stack.head != NULL || stack.tail != NULL)
	{
		if (stack.head != NULL)
		{
			if (stack.head->value == find)
				return (i);
			stack.head = stack.head->next;
		}
		if (stack.tail != NULL)
		{
			if (stack.tail->value == find)
				return (-i);
			stack.tail = stack.tail->prev;
		}
		i++;
	}
	return (0);
}

int	ps_find_less(t_stack a, int pivot)
{
    int	i;

	i = 1;
	if (a.head == NULL)
		return (0);
	while (a.head != a.tail && a.head->prev != a.tail)
	{
		if (a.head->value < pivot)
			return (i);
		a.head = a.head->next;
		if (a.tail->value < pivot)
			return (-1 * i);
		a.tail = a.tail->prev;
		i++;
	}
	if (a.head->value < pivot)
		return (i);
	return (0);
}

long	diff_abs(long a, long b)
{
	long	c;

	c = a - b;
	if (c < 0)
		return (-c);
	return (c);
}

void	ps_a_to_b(t_stack *a, t_stack *b, int i)
{
	if (i > 0)
	{
		while (i > 1)
		{
			ps_pipeline(ROTATE_A, a, b);
			i--;
		}
		ps_pipeline(PUSH_B, a, b);
	}
	else if (i < 0)
	{
		while (i <= -1)
		{
			ps_pipeline(REV_ROTATE_A, a, b);
			i++;
		}
		ps_pipeline(PUSH_B, a, b);
	}
}