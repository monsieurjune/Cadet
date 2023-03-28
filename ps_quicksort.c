/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:56:28 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/27 04:59:16 by tponutha         ###   ########.fr       */
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

static t_node	*sb_partfefefition(t_stack *a, t_stack *b, t_node *l, t_node **h)
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
	- choose pivot (first partition)
	- put pivot to Stack B 
	- <pivot -> send to B
	- >pivot -> do nothing
	- when done, send pivot back to A ???
2.) Patitioning A stack (in asending order)
	- choose pivot (first partiotion)
	- memolise top of B
	- <pivot -> send to B
	- do it recursively, until
		- there is less than 1 adject value to pivot
		- swap it if pivot > adject
	- then put back from B to A
3.) Partiotioning B Stack (in desending order)
	-
4.) Put B back to A
*/

// first partition

void	sb_partition(t_stack *a, t_stack *b, int low, int high)
{

}

void	ps_quicksort(t_stack *a, t_stack *b, int low, int high)
{
	if (low > high)
	{
		if (a->head->value > a->tail->value)
			ps_pipeline(SWAP_A, a, b);
		return ;
	}
	else
		//
	
}


// There is Bug