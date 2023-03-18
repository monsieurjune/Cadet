/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:39:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/16 09:15:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	*sb_clone_arr(int *arr, int size, t_listmem **head)
{
	int	*clone;

	clone = lm_malloc(sizeof(int), size, head);
	if (clone == NULL)
		return (NULL);
	clone = ft_memmove(clone, arr, sizeof(int) * size);
	return (clone);
}

static int	sb_first_partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[low];
	i = low;
	j = low + 1;
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_intswap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_intswap(&arr[i], &arr[low]);
	return (i);
}

static void	sb_quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low >= high)
		return ;
	pi = sb_first_partition(arr, low, high);
	sb_quicksort(arr, low, pi - 1);
	sb_quicksort(arr, pi + 1, high);
}

int	stack_isduplicate(int *arr, int size, t_listmem **head)
{
	int	i;
	int	*copy;

	i = 1;
	copy = sb_clone_arr(arr, size, head);
	if (copy == NULL)
		stack_exit(head);
	sb_quicksort(copy, 0, size - 1);
	while (i < size)
	{
		if (copy[i] == copy[i - 1])
			return (TRUE);
		i++;
	}
	lm_free(copy, head);
	return (FALSE);
}

/*
#include <stdio.h>
#include <time.h>
int	*random_num_gen(int size, t_listmem **head)
{
	time_t	s;

	srand(time(&s));
	int	*arr = lm_malloc(sizeof(int), size, head);
	if (arr == NULL)
		stack_exit(head);
	int i = 0;
	while (i < size)
	{
		arr[i] = rand();
		i++;
	}
	return (arr);
}

int	check_sort(int *arr, int size)
{
	int i = 1;

	while (i < size)
	{
		if (arr[i] < arr[i - 1])
		{
			printf("problem i:%d -> i-1:%d\n", arr[i], arr[i - 1]);
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;

	t_listmem *head = NULL;
	
	int size = atoi(av[1]);
	int *arr = random_num_gen(size, &head);
	sb_quicksort(arr, 0, size - 1);
	if (check_sort(arr, size) == 0)
		printf("sort algoritm has problem\n");
	else
		printf("everything is fine\n");
	stack_exit(&head);
}
*/