/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:55:23 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/06 15:13:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*stack_create_node(int value, t_listmem **head)
{
	t_stack	*node;

	node = lm_malloc(sizeof(t_stack), 1, head);
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack **stack, t_stack *node)
{
	if (node == NULL)
		return ;
	if (*stack == NULL)
		*stack = node;
	else
	{
		node->next = *stack;
		*stack = node;
	}
}

t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*head;

	if (*stack == NULL)
		return (NULL);
	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	return (head);
}

t_stack	*stack_build(int *arr, int lastpos, t_listmem **head)
{
	t_stack	*stack;
	t_stack	*node;

	stack = NULL;
	while (lastpos > 0)
	{
		node = stack_create_node(arr[lastpos - 1], head);
		if (node == NULL)
			stack_exit(head);
		stack_push(&stack, node);
		lastpos--;
	}
	lm_free(arr, head);
	return (stack);
}