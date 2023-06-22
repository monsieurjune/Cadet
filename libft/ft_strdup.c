/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:28 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 18:18:09 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size + 1 because use of strlen only count
// how many charactors are, except counting 0
// so size = ft_strlen(str) + 1

char	*ft_strdup(const char *src, t_list **head)
{
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dest = ft_malloc(sizeof(char), len + 1, head);
	if (!dest)
		return (NULL);
	(void)ft_strlcpy(dest, src, len + 1);
	return (dest);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char *b;
	b = ft_strdup(av[1]);
	printf("%s\n",b);
	free(b);
	return (0);
}
*/
