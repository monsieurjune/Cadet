/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:31:16 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 21:53:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
int main()
{
	t_list *l = NULL;
	ft_lstdelone(l, free);
	for (int i = 0; i < 100; i++)
		ft_lstadd_back(&l, ft_lstnew(&"5"));
		//ft_lstadd_back(&l, ft_lstnew(calloc(sizeof(int), 5)));
	ft_lstclear(&l, free);
	return (0);
}
*/