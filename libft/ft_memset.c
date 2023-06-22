/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:12:01 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/31 15:22:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t byte)
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

/*
#include <string.h>
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	int bit = atoi(av[1]);
	int bits = atoi(av[2]);

	int i = 0;
	int *b = malloc(7 * 4);
	b = memset(b, bit, bits);
	printf("------------STD-------------\n");
	while (i < 6)
	{
		printf("%d.) %d\n", i, b[i]);
		i++;
	}
	int *c = malloc(7 * 4);
	c = ft_memset(c, bit, bits);
	i = 0;
	printf("------------USR-------------\n");
	while (i < 7)
	{
		printf("%d.) %d\n", i, c[i]);
		i++;
	}
	free(b);
	free(c);
	return (0);
}
*/
