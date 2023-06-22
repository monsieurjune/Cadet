/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:10:48 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 00:36:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newc)
{
	t_list	*oldhead;

	oldhead = *lst;
	*lst = newc;
	(*lst)->next = oldhead;
}

/*
int main(int ac, char **av)
{
	t_list	*ls1;
	t_list	*ls2;

	ls1 = NULL;
	ls2 = NULL;
	for (int i = 1; i < ac; i++)
	{
		ft_lstadd_front(&ls1, ft_lstnew(ft_strdup(av[i])));
		ft_lstadd_back(&ls2, ft_lstnew(ft_strdup(av[i])));
	}
	ft_lstclear(&ls1, free);
	ft_lstclear(&ls2, free);
	return (0);
}
*/