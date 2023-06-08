/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:38:59 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 01:16:51 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!find || !find[0] || !str)
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (find[j] && i + j < n)
			{
				if (str[i + j] != find[j])
					break ;
				j++;
			}
			if (find[j] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	char	cmp;
	size_t	lastpos;

	if (!str)
		return (NULL);
	lastpos = ft_strclen(str, 0);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 == 0 || s2 == 0 || n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != 0 || s2[i] != 0) && i < n)
		i++;
	return ((unsigned char)s1[i - (i == n)] - (unsigned char)s2[i - (i == n)]);
}

char	*ft_strnchr(const char *str, size_t n, int c)
{
	size_t	i;
	char	cmp;

	i = 0;
	cmp = (char)c;
	if (!str)
		return (NULL);
	while (i < n && str[i] != 0)
	{
		if (str[i] == cmp)
			return ((char *)str);
		i++;
	}
	if (str[i] == cmp)
		return ((char *)str);
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
