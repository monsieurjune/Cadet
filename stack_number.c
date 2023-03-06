/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:39:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/06 18:14:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
static int	sb_get_absulutemax(int *array, int size)
{
	int	i;
	int	max;
	int	cmp;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (array[i] == -2147483648)
			return (-2147483648);
		cmp = array[i];
		if (cmp < 0)
			cmp *= -1;
		if (cmp > max)
			max = cmp;
		i++;
	}
	return (max);
}

static void	sb_counter(int *arr, int size, int bucket[], long power)
{
	int	i;
	int	point;

	i = 0;
	stack_memset(bucket, 0, 256 * sizeof(int));
	while (i < size)
	{
		point = 128 * (arr[i] >= 0) + 127 * !(arr[i] >= 0);
		bucket[point + (arr[i] / power) % 128]++;
		i++;
	}
	i = 1;
	while (i < 256)
	{
		bucket[i] += bucket[i - 1];
		i++;
	}
}

static int	*sb_countsort(int *arr, int size, long power, t_listmem **head)
{
	int	i;
	int	pos;
	int	point;
	int	bucket[256];
	int	*output;

	output = lm_malloc(sizeof(int), size, head);
	if (output == NULL)
		stack_exit(head);
	sb_counter(arr, size, bucket, power);
	i = size - 1;
	while (i >= 0)
	{
		point = 128 * (arr[i] >= 0) + 127 * !(arr[i] >= 0);
		pos = point + (arr[i] / power) % 128;
		output[bucket[pos] - 1] = arr[i];
		bucket[pos]--;
		i--;
	}
	lm_free(arr, head);
	return (output);
}

static int	*sb_radixsort_array(int *arr, int size, t_listmem **head)
{
	int		*copy;
	long	power;
	int		max;

	power = 1;
	max = sb_get_absulutemax(arr, size);
	copy = lm_malloc(sizeof(int), size, head);
	if (copy == NULL)
		stack_exit(head);
	copy = stack_memmove(copy, arr, size * sizeof(int));
	while (max / power != 0)
	{
		copy = sb_countsort(copy, size, power, head);
		power *= 128;
	}
	return (copy);
}
*/

static int	*sb_clone_arr(int *arr, int size, t_listmem **head)
{
	int	*clone;

	clone = lm_malloc(sizeof(int), size, head);
	if (clone == NULL)
		return (NULL);
	clone = stack_memmove(clone, arr, sizeof(int) * size);
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
			stack_num_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	stack_num_swap(&arr[i + 1], &arr[low]);
	return (i + 1);
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

/*
int main()
{
	t_listmem *head = NULL;

	int size = 3;
	int arr[3] = {1871350148, 371815938, -2147483648};
	int	*out = sb_radixsort_array(arr, size, &head);
	if (check_sort(out, size) == 0)
		printf("sort algoritm has problem\n");
	else
		printf("everything is fine\n");
	stack_exit(&head);
}
*/
