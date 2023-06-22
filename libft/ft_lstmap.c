/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:31:27 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 00:38:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*sub_failsafe(t_list **lst, t_list **node, void (*del)(void *))
{
	if (*node)
		free(*node);
	ft_lstclear(lst, del);
	return (NULL);
}

void	sub_add_back(t_list **lst, t_list *newc)
{
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = newc;
	}
	else
		*lst = newc;
}

// add new node at back of main list
// dont use ft_lstadd_back due to time complexity

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*tail;
	t_list	*head;

	tail = NULL;
	while (lst)
	{
		node = ft_lstnew(NULL);
		if (!node)
			return (sub_failsafe(&tail, &node, del));
		node->content = f(lst->content);
		if (!node->content)
			return (sub_failsafe(&tail, &node, del));
		if (!tail)
			head = node;
		sub_add_back(&tail, node);
		lst = lst->next;
	}
	return (head);
}

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlst;

	newlst = NULL;
	while (lst)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		node->content = f(lst->content);
		if (!node->content)
		{
			free(node);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst, node);
		lst = lst->next;
	}
	return (newlst);
}
*/
