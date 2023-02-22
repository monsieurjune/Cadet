/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:57:23 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 21:57:21 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = stack_pop(stack);
	second = stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void	stack_pop_push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = stack_pop(src);
	stack_push(dest, node);
}

void	stack_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*node;

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

void	stack_reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*almost_last;

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