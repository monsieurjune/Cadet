/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:42:22 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/08 14:54:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || size < 1 || !src)
		return (srclen);
	i = 0;
	if (size > srclen + 1)
		size = srclen + 1;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[size - 1] = 0;
	return (srclen);
}

/*
#include <string.h>
size_t strlcpy(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen < maxlen) {
        memcpy(dst, src, srclen+1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen-1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char a[30];
	memset(a, 'A', 30);
	char b[30];
	unsigned long la = strlcpy(a,"",atoi(av[2]));
	unsigned long lb = ft_strlcpy(b, "", atoi(av[2]));
	printf("STD : %ld -> %s\n", la, a);
	printf("USR : %ld -> %s\n", lb, b);
}
*/