/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:06:02 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 17:11:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flush(t_list **head)
{
	t_list	*front;

	while (*head != NULL)
	{
		front = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = front;
	}
}
