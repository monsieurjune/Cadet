/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:57:23 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/18 17:26:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = stack_pop(stack);
	second = stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void	stack_pop_push(t_node **dest, t_node **src)
{
	t_node	*node;

	if (*src == NULL)
		return ;
	node = stack_pop(src);
	stack_push(dest, node);
}

void	stack_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*node;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	node = stack_pop(stack);
	head = *stack;
	while (head->next != NULL)
		head = head->next;
	head->next = node;
}

void	stack_reverse_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*almost_last;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	head = *stack;
	while (head->next != NULL)
	{
		almost_last = head;
		head = head->next;
	}
	almost_last->next = NULL;
	stack_push(stack, head);
}

void	stack_exit(t_mem **head)
{
	lm_flush(head);
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}