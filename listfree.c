/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:23:44 by tponutha          #+#    #+#             */
/*   Updated: 2023/02/11 17:50:08 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listmem.h"

static void	lm_free_node(t_listmem **head, t_listmem *node, t_listmem *prev)
{
	if (prev == NULL)
		*head = (*head)->next;
	else
		prev->next = node->next;
	free(node->mem);
	free(node);
}

void	lm_free(void *byte, t_listmem **head)
{
	t_listmem	*runner;
	t_listmem	*prev;

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

void	lm_flush(t_listmem **head)
{
	t_listmem	*front;

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
