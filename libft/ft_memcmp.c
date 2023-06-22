/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:17:17 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/28 20:59:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t			i;
	unsigned char	*m1;
	unsigned char	*m2;

	if (!p1 || !p2 || !n)
		return (0);
	i = 0;
	m1 = (unsigned char *)p1;
	m2 = (unsigned char *)p2;
	while (i < n)
	{
		if (m1[i] != m2[i])
			break ;
		i++;
	}
	return (m1[i - (i == n)] - m2[i - (i == n)]);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", memcmp("Hello", "World", 0));
	return (0);
}
*/