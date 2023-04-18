/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:23:44 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 05:07:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astable.h"

static void	lm_free_node(t_mem **head, t_mem *node, t_mem *prev)
{
	if (prev == NULL)
		*head = (*head)->next;
	else
		prev->next = node->next;
	free(node->mem);
	free(node);
}

void	as_free(void *byte, t_mem **head)
{
	t_mem	*runner;
	t_mem	*prev;

	prev = NULL;
	runner = *head;
	while (runner != NULL)
	{
		if (runner->mem == byte)
		{
			lm_free_node(head, runner, prev);
			return ;
		}
		prev = runner;
		runner = runner->next;
	}
}

void	as_flush_mem(t_mem **head)
{
	t_mem	*front;

	if (*head == NULL )
		return ;
	while (*head != NULL)
	{
		front = (*head)->next;
		free((*head)->mem);
		free(*head);
		*head = front;
	}
}
