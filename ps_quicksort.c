/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:56:28 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/26 18:19:17 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



/* Inward Search Algorithm
- low & high try to approching each other
	- if node->value < pivot
		- return node
	- if not then continue
- stop when low == high
	- if low->value < pivot then return low
	- if not then return NULL
- it's impossible for low & high to meet NULL before meet each other
*/

static t_node	*sb_search_less(int pivot, t_node *low, t_node *high)
{
	
}

/* IDEA of PARTITION (first partition)
- choose pivot
- send everything <pivot to left of pivot
	- in this case, send to b
- send everything >pivot to right of pivot
	- in this case, do nothing
- when done, send all b to top of pivot
- return pivot's node 
*/

static t_node	*sb_partition(t_stack *a, t_stack *b, t_node *l, t_node **h)
{
	t_node	*move;
	int		pivot;

	pivot = l->value;
	l = l->next;
	while (1)
	{
		move = sb_search_less(pivot, l, *h);
		if (move == NULL)
			break ;
		if (move == *h)
			*h = (*h)->prev;
		ps_a_to_b(a, b, move);
	}
	//ps_putback_to_a(a, b);
	return (l);
}

/*	Quick sort idea
1.) Separate Stack into 2 stack
	- chose pivot (first partition)
	- <pivot -> send to b
	- >pivot ->stay below pivot
2.) Patitioning A stack (in aswnding order)
	-
3.) Partiotioning B Stack (in desending order)
	-
4.) Put B back to A
*/

void	ps_quicksort(t_stack *a, t_stack *b, t_node *low, t_node *high)
{
	t_node	*pi;

	if (ps_node_search(low, high) >= 0)
		return ;
	pi = sb_partition(a, b, low, &high);
	ps_quicksort(a, b, low, pi->prev);
	ps_quicksort(a, b, pi->next, high);
}


// There is Bug