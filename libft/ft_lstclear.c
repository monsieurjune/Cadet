/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:31:09 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 21:54:09 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// del -> free content
// free -> free pointer

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*front;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		front = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = front;
	}
}
