/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:30:53 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 20:25:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newc)
{
	t_list	*head;

	if (*lst)
	{
		head = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = newc;
		*lst = head;
	}
	else
		*lst = newc;
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int  i = 1;
	a = malloc(sizeof(t_list));
	a->content = av[0];
	a->next = NULL;
	while (i < ac)
	{
		b = malloc(sizeof(t_list));
		b->content = av[i];
		b->next = NULL;
		ft_lstadd_back(&a, b);
		i++;
	}
	while (a)
	{
		printf("%s\n", (char *)a->content);
		a = a->next;
	}
}
*/
