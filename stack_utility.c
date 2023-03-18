/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:54:54 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/16 16:05:43 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] || str[len] != c)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strclen(src, 0);
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

static size_t	sub_total(char *dest, const char *src, size_t size)
{
	size_t	total;

	total = ft_strclen(dest, 0);
	if (total > size)
		total = size;
	total += ft_strclen(src, 0);
	return (total);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	destlen;

	if (dst == 0 || src == 0)
		return (0);
	destlen = ft_strclen(dst, 0);
	total = sub_total(dst, src, size);
	if (destlen + 1 >= size)
		return (total);
	i = 0;
	while (src[i] != 0 && destlen + i + 1 < size)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = 0;
	return (total);
}