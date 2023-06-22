/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:30:16 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/31 15:16:55 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t byte)
{
	size_t	i;

	if (!dst || !src || !byte)
		return (dst);
	i = 0;
	while (i < byte)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	int bit = atoi(av[1]);
	int bits = atoi(av[2]);
    int n = atoi(av[3]);

	int i = 0;
	int *a = malloc(7 * 4);
	a = memset(a, bit, bits);
    int *b = malloc(28);
    b = memcpy(b, a, n);
	printf("------------STD-------------\n");
	while (i < 7)
	{
		printf("%d.) %d\n", i, b[i]);
		i++;
	}
	printf("------------USR-------------\n");
    i = 0;
    int *c = malloc(28);
    c = memcpy(c, a, n);
	while (i < 7)
	{
		printf("%d.) %d\n", i, c[i]);
		i++;
	}
    free(a);
	free(b);
	free(c);
	return (0);
}

int	main()
{
	char *d = "Hello";
	char *s = "NULL";

	printf("memcpy = %s", memcpy(d, s, 0));
	printf("\nft_memcpy = %s", ft_memcpy(d, s, 0));
	return (0);
}
*/
