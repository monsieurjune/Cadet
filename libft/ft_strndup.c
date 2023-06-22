/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:52:10 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 22:51:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len, t_list **head)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = ft_malloc(sizeof(char), len + 1, head);
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
