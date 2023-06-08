/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:13:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 04:19:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	destlen;

	if (dst == 0 || src == 0)
		return (0);
	destlen = ft_strclen(dst, 0);
	total = ft_strclen(dst, 0);
	if (total > size)
		total = size;
	total += ft_strclen(src, 0);
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

char	*ft_strjoin(char const *s1, char const *s2, t_mem **head)
{
	char	*str;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_strclen(s1, 0) + ft_strclen(s2, 0) + 1;
	str = lm_malloc(sizeof(char), size, head);
	if (!str)
		return (NULL);
	(void)ft_strlcpy(str, s1, size);
	(void)ft_strlcat(str, s2, size);
	return (str);
}

char	*ft_threemany(char const *s1, char const *s2, int n, t_mem **head)
{
	char	*str;
	size_t	size;
	size_t	s1_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strclen(s1, 0);
	size = s1_len + n + 2;
	str = lm_malloc(sizeof(char), size, head);
	if (!str)
		return (NULL);
	(void)ft_strlcpy(str, s1, s1_len + 1);
	str[s1_len] = '/';
	str[s1_len + 1] = 0;
	(void)ft_strlcat(str, s2, size);
	return (str);
}
