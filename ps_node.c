/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:36:47 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/27 04:04:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Search Hierachy
[more positive]
+m <- head
...
+x <- Search Node (above start)
...
+3
+2
+1
0 <- Start Node ^ v
-1
-2
-3
...
-y <- Search Node (under start)
...
-n <- tail
[more negative]
*/

int	ps_node_search(t_node *start, int find)
{
	t_node	*bottom;
	int		i;

	i = 0;
	bottom = start;
	if (start->value == find)
		return (0);
	while (start != NULL || bottom != NULL)
	{
		if (start != NULL)
		{
			if (start->value == find)
				return (i);
			start = start->prev;
		}
		if (bottom != NULL)
		{
			if (bottom->value == find)
				return (-i);
			bottom = bottom->next;
		}
		i++;
	}
	return (INT_MAX);
}

/* DEPTH
positive = near head
negative = near tail
zero = not found
*/

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

void	ps_a_to_b(t_stack *a, t_stack *b, int val)
{
	int	i;

	i = ps_node_depth(*a, val);
	if (i > 0)
	{
		while (i > 2)
		{
			ps_pipeline(ROTATE_A, a, b);
			i--;
		}
		ps_pipeline(SWAP_A, a, b);
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
