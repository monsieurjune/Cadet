/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:08:01 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/31 15:23:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t byte)
{
	size_t			i;
	unsigned char	cmp;

	if (!ptr)
		return (NULL);
	i = 0;
	cmp = (unsigned char)c;
	while (i < byte)
	{
		if (((unsigned char *)ptr)[i] == cmp)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
