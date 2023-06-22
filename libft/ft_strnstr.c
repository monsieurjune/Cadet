/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:38:59 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 22:38:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	sub_check(const char *str, const char *find, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (find[j] && i + j < n)
	{
		if (str[i + j] != find[j])
			return (0);
		j++;
	}
	return (find[j] == 0);
}

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;

	if (!find || !find[0])
		return ((char *)str);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == find[0])
			if (sub_check(str, find, i, n))
				return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

char *
strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	main(int ac, char **av)
{
	(void)ac;
    char *a = strnstr(av[1], av[2], atoi(av[3]));
	char *b = ft_strnstr(av[1], av[2], atoi(av[3]));
    printf("STD : %s : (%s) ---> |%s\n",av[1],av[2],a);
	printf("USR : %s : (%s) ---> |%s\n",av[1],av[2],b);
	return (0);
}
*/
