/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:54:54 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/06 17:53:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*stack_memset(void *ptr, int c, size_t byte)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < byte)
	{
		((unsigned char *)ptr)[i] = ((unsigned char *)&c)[0];
		i++;
	}
	return (ptr);
}

void	stack_exit(t_listmem **head)
{
	lm_flush(head);
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	*stack_memmove(void *dst, const void *src, size_t byte)
{
	size_t	i;
	size_t	diff;

	if (!dst || !src || !byte)
		return (dst);
	i = (byte - 1) * (dst > src);
	diff = 1;
	if (dst > src)
		diff = -1;
	while (i < byte)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += diff;
		if (i == 0)
		{
			((unsigned char *)dst)[0] = ((unsigned char *)src)[0];
			break ;
		}
	}
	return (dst);
}

void	stack_num_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}