/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:32:41 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/16 09:00:17 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
PUSHSWAP INSTRUCTION
1: check error in av
*/



int	main(int ac, char **av)
{
	t_listmem	*ps_mem;
	t_stack		*a;
	t_stack		*b;

	if (ac <= 1)
		return (0);
	ps_mem = NULL;
	
	lm_flush(&ps_mem);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
void test_print(t_stack *a, t_stack *b)
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