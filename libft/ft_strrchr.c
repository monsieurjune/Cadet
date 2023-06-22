/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:27:06 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/03 23:37:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	cmp;
	size_t	lastpos;

	if (!str)
		return (NULL);
	lastpos = ft_strlen(str);
	cmp = (char)c;
	while (lastpos)
	{
		if (str[lastpos] == cmp)
			return ((char *)&str[lastpos]);
		lastpos--;
	}
	if (str[0] == cmp)
		return ((char *)&str[lastpos]);
	return (NULL);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s",ft_strrchr(av[1], av[2][0]));
	return 0;
}
*/