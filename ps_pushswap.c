/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:32:41 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/18 17:26:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
PUSHSWAP INSTRUCTION
1: check error in av
2: check if it sorted yet
3: if everything correct then
	- init value
	- sort it
*/

static int	sb_issorted(int *arr, int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (TRUE);
	while (i < len)
	{
		if (arr[i] < arr[i - 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_mem	*ps_mem;
	t_node		*a;
	t_node		*b;
	int			*arr;
	int			len;

	if (ac <= 1)
		return (0);
	arr = stack_check_n_return(ac, &len, av, &ps_mem);
	if (!sb_issorted(arr, len))
	{
		a = stack_build(arr, len, &ps_mem);
		b = NULL;
	}
	lm_flush(&ps_mem);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
void test_print(t_node *a, t_node *b)
{
	printf("a	b\n");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("%d	", a->value);
			a = a->next;
		}
		else
			printf("_	");
		if (b != NULL)
		{
			printf("%d\n", b->value);
			b = b->next;
		}
		else
			printf("_\n");
	}
	printf("\n-------------------\n");
}
*/