/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:46:43 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/25 17:01:20 by tponutha         ###   ########.fr       */
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

void	ps_putback_to_a(t_stack *a, t_stack *b)
{
	while (b->head != NULL)
		ps_pipeline(PUSH_A, a, b);
}

/*
#include <stdio.h>
#include <string.h>
void test_print(t_stack a, t_stack b)
{
	printf("a	b\n");
	while (a.head != NULL || b.head != NULL)
	{
		if (a.head != NULL)
		{
			printf("%d	", a.head->value);
			a.head = a.head->next;
		}
		else
			printf("_	");
		if (b.head != NULL)
		{
			printf("%d\n", b.head->value);
			b.head = b.head->next;
		}
		else
			printf("_\n");
	}
	printf("\n-------------------\n");
}

int	main(int ac, char **av)
{
	int i = 1;
	t_mem	*head = NULL;
	int *arr = lm_malloc(sizeof(int), ac - 1, &head);
	while (i < ac)
	{
		arr[i - 1] = atoi(av[i]);
		i++;
	}
	t_stack	a = stack_build(arr, ac - 1, &head);
	t_stack b = stack_build(NULL, 0, &head);
	test_print(a, b);
	char read[10];
	while (1)
	{
		scanf("%s", read);
		if (strcmp("EXIT", read) == 0)
			break;
		int cmd = atoi(read);
		ps_pipeline(cmd, &a, &b);
		test_print(a, b);
	}
	stack_exit(&head);
}
*/