/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:01:38 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 00:20:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t byte)
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

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *a = malloc(10);

	a = ft_memset(a, 4, 10);
	a = ft_memset(a, 3, 5);
	for (int i = 0; i < 10; i++)
	{
		printf("%d.) %d\n", i, a[i]);
	}
	printf("-------------A---------------\n");
	ft_memmove(a, a + 4, 4);
	for (int i = 0; i < 10; i++)
	{
		printf("%d.) %d\n", i, a[i]);
	}
	printf("-------------B---------------\n");
	char *b = malloc(10);

	b = ft_memset(a, 4, 10);
	b = ft_memset(a, 3, 5);
	b = ft_memmove(b, NULL, 0);
	for (int i = 0; i < 10; i++)
	{
		printf("%d.) %d\n", i, b[i]);
	}
	printf("-------------C---------------\n");
	char *c = malloc(10);

	c = ft_memset(a, 4, 10);
	c = ft_memset(a, 3, 5);
	memmove(c, NULL, 0);
	for (int i = 0; i < 10; i++)
	{
		printf("%d.) %d\n", i, c[i]);
	}
	return (0);
}
*/