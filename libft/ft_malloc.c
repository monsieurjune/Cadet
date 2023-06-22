/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:45:26 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 17:11:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t byte, size_t size, t_list **head)
{
	t_list	*node;
	void	*mem;

	if (byte == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	byte *= size;
	mem = malloc(byte);
	if (mem == NULL)
		return (NULL);
	node = ft_lstnew(mem);
	if (node == NULL)
	{
		free(mem);
		return (NULL);
	}
	ft_lstadd_front(head, node);
	return (mem);
}
