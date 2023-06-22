/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:27:33 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 16:47:20 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t byte, size_t size, t_list **head)
{
	void	*mem;

	mem = ft_malloc(byte, size, head);
	if (mem == NULL)
		return (NULL);
	return (ft_memset(mem, 0, byte * size));
}

// void	*ft_calloc(size_t byte, size_t size)
// {
// 	void	*mem;

// 	if (byte == SIZE_MAX || size == SIZE_MAX)
// 		return (NULL);
// 	byte *= size;
// 	mem = malloc(byte);
// 	if (!mem)
// 		return (NULL);
// 	return (ft_memset(mem, 0, byte));
// }

/*
#include <stdio.h>
int main(int ac, char **av)
{
	int *a = ft_calloc(ac, 4);
	for (int i = 0; i < ac; i++)
	{
		a[i] = atoi(av[i]);
	}
	for (int i = 0; i < ac; i++)
	{
		printf("%d.) %d\n", i, a[i]);
	}
	return (0);
}
*/