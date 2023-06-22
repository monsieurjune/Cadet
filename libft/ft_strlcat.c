/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:51:04 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/06 11:17:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sub_total(char *dest, const char *src, size_t size)
{
	size_t	total;

	total = ft_strlen(dest);
	if (total > size)
		total = size;
	total += ft_strlen(src);
	return (total);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	destlen;

	if (dst == 0 || src == 0)
		return (0);
	destlen = ft_strlen(dst);
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
