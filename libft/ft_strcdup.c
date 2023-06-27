/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:36:50 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 17:42:49 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, char c, t_list **head)
{
	size_t	len;
	char	*dest;

	len = ft_strclen(src, c);
	dest = ft_malloc(sizeof(char), len + 1, head);
	if (dest == NULL)
		return (NULL);
	(void)ft_strlcpy(dest, src, len + 1);
	return (dest);
}
