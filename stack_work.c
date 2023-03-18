/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:55:23 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/18 17:53:48 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_node **stack, t_node *node)
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

t_node	*stack_pop(t_node **stack)
{
	t_node	*head;

	if (*stack == NULL)
		return (NULL);
	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	return (head);
}

static t_node	*stack_create_node(int value, t_mem **head)
{
	t_node	*node;

	node = lm_malloc(sizeof(t_node), 1, head);
	if (node == NULL)
		stack_exit(head);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_node	*stack_build(int *arr, int lastpos, t_mem **head)
{
	t_node	*stack;
	t_node	*node;

	stack = NULL;
	while (lastpos > 0)
	{
		node = stack_create_node(arr[lastpos - 1], head);
		stack_push(&stack, node);
		lastpos--;
	}
	lm_free(arr, head);
	return (stack);
}

t_stack	stack_initialize(int *arr, int lastpos, t_mem **head)
{
	t_stack	stack;
	t_node	*run;

	if (arr != NULL)
	{
		stack.head = stack_build(arr, lastpos, head);
		run = stack.head;
		while (run->next != NULL)
			run = run->next;
		stack.tail = run;
		return (stack);
	}
	stack.head = NULL;
	stack.tail = NULL;
	return (stack);
}