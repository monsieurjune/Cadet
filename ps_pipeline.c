/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:46:43 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/10 13:10:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ps_print_cmd(int cmd)
{
	if (cmd == SWAP_A)
		write(1, STR_SWAP_A, sizeof(STR_SWAP_A) - 1);
	else if (cmd == SWAP_B)
		write(1, STR_SWAP_B, sizeof(STR_SWAP_B) - 1);
	else if (cmd == SWAP_AB)
		write(1, STR_SWAP_AB, sizeof(STR_SWAP_AB) - 1);
	else if (cmd == PUSH_A)
		write(1, STR_PUSH_A, sizeof(STR_PUSH_A) - 1);
	else if (cmd == PUSH_B)
		write(1, STR_PUSH_B, sizeof(STR_PUSH_B) - 1);
	else if (cmd == ROTATE_A)
		write(1, STR_ROTATE_A, sizeof(STR_ROTATE_A) - 1);
	else if (cmd == ROTATE_B)
		write(1, STR_ROTATE_B, sizeof(STR_ROTATE_B) - 1);
	else if (cmd == ROTATE_AB)
		write(1, STR_ROTATE_AB, sizeof(STR_ROTATE_AB) - 1);
	else if (cmd == REV_ROTATE_A)
		write(1, STR_REV_ROTATE_A, sizeof(STR_REV_ROTATE_A) - 1);
	else if (cmd == REV_ROTATE_B)
		write(1, STR_REV_ROTATE_B, sizeof(STR_REV_ROTATE_B) - 1);
	else if (cmd == REV_ROTATE_AB)
		write(1, STR_REV_ROTATE_AB, sizeof(STR_REV_ROTATE_AB) - 1);
	write(1, "\n", 1);
}

static void	ps_do_both(int cmd, t_stack *a, t_stack *b)
{
	if (cmd == SWAP_AB)
	{
		stack_swap(a);
		stack_swap(b);
	}
	else if (cmd == ROTATE_AB)
	{
		stack_rotate(a);
		stack_rotate(b);
	}
	else if (cmd == REV_ROTATE_AB)
	{
		stack_reverse_rotate(a);
		stack_reverse_rotate(b);
	}
}

void	ps_pipeline(int cmd, t_stack *a, t_stack *b)
{
	if (cmd == SWAP_A)
		stack_swap(a);
	else if (cmd == SWAP_B)
		stack_swap(b);
	else if (cmd == PUSH_A)
		stack_pop_push(a, b);
	else if (cmd == PUSH_B)
		stack_pop_push(b, a);
	else if (cmd == ROTATE_A)
		stack_rotate(a);
	else if (cmd == ROTATE_B)
		stack_rotate(b);
	else if (cmd == REV_ROTATE_A)
		stack_reverse_rotate(a);
	else if (cmd == REV_ROTATE_B)
		stack_reverse_rotate(b);
	else
		ps_do_both(cmd, a, b);
	ps_print_cmd(cmd);
}

void	ps_a_to_b(t_stack *a, t_stack *b, int i)
{
	if (i > 0)
	{
		while (i > 1)
		{
			ps_pipeline(ROTATE_A, a, b);
			i--;
		}
		ps_pipeline(PUSH_B, a, b);
	}
	else if (i < 0)
	{
		while (i <= -1)
		{
			ps_pipeline(REV_ROTATE_A, a, b);
			i++;
		}
		ps_pipeline(PUSH_B, a, b);
	}
}

/*
#include <stdio.h>
#include <string.h>
int sb_bottom_index(t_stack a, int bottom)
{
    int	i;

	i = 0;
	if (a.head == NULL)
		return (-1);
	while (a.head != a.tail && a.head->prev != a.tail)
	{
		if (a.head->value == bottom)
			return (i);
		a.head = a.head->next;
		if (a.tail->value == bottom)
			return (a.n - i - 1);
		a.tail = a.tail->prev;
		i++;
	}
	if (a.head->value == bottom)
		return (i);
	return (-1);
}

void test_print(t_stack a, t_stack b)
{
	t_node	*runa = a.head;
	t_node	*runb = b.head;

	printf("a	b\n");
	while (runa != NULL || runb != NULL)
	{
		if (runa != NULL)
		{
			printf("%d	", runa->value);
			runa = runa->next;
		}
		else
			printf("_	");
		if (runb != NULL)
		{
			printf("%d\n", runb->value);
			runb = runb->next;
		}
		else
			printf("_\n");
	}
	printf("\n-------------------\n");
}

int	main(int ac, char **av)
{
	int i = 1;
	int cmd;
	t_mem	*head = NULL;
	int *arr = lm_malloc(sizeof(int), ac - 1, &head);
	while (i < ac)
	{
		arr[i - 1] = atoi(av[i]);
		i++;
	}
	printf("%d\n", ac - 1);
	t_stack	a = stack_build(arr, ac - 1, &head);
	t_stack b = stack_build(NULL, 0, &head);
	test_print(a, b);
	char read[10];
	while (1)
	{
		scanf("%s", read);
		if (strcmp("EXIT", read) == 0)
			break;
		if (strcmp("sa", read) == 0)
			cmd = SWAP_A
		ps_pipeline(cmd, &a, &b);
		test_print(a, b);
	}
	stack_exit(&head);
}
*/