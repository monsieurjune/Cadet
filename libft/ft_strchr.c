/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:09:03 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/03 22:48:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cmp;

	cmp = (char)c;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == cmp)
			return ((char *)str);
		str++;
	}
	if (*str == cmp)
		return ((char *)str);
	return (NULL);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s",ft_strchr(av[1], 't' + 256));
	return 0;
}
*/