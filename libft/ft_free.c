/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:51:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 17:00:06 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *mem, t_list **head)
{
	t_list	*run;
	t_list	*prev;

	run = *head;
	prev = NULL;
	if (run == NULL)
		return ;
	while (run != NULL)
	{
		if (run->content == mem)
		{
			if (prev == NULL)
				*head = (*head)->next;
			else
				prev->next = run->next;
			free(run->content);
			free(run);
			return ;
		}
		prev = run;
		run = run->next;
	}
}
