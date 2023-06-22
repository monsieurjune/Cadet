/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:25:02 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 18:22:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 : get index to first index of non-trim;
2 : get index to last index of non-trim;
3 : find non-trim length and ft_malloc it
4 : use strncpy to copy str
*/

static _Bool	sub_isnt_in(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (0);
		set++;
	}
	return (1);
}

static size_t	sub_first_pos(const char *s1, const char *set)
{
	size_t	pos;

	pos = 0;
	while (s1[pos])
	{
		if (sub_isnt_in(s1[pos], set))
			return (pos);
		pos++;
	}
	return (pos);
}

static size_t	sub_last_pos(const char *s1, const char *set)
{
	size_t	pos;

	pos = ft_strlen(s1) - 1;
	while (1)
	{
		if (sub_isnt_in(s1[pos], set))
			return (pos);
		if (pos == 0)
			break ;
		pos--;
	}
	return (pos);
}

char	*ft_strtrim(char const *s1, char const *set, t_list **head)
{
	size_t	firstpos;
	size_t	lastpos;
	size_t	size;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1, head));
	firstpos = sub_first_pos(s1, set);
	if (s1[firstpos] == 0)
		return (ft_calloc(sizeof(char), 1, head));
	lastpos = sub_last_pos(s1, set);
	size = lastpos - firstpos + 2;
	str = ft_malloc(sizeof(char), size, head);
	if (!str)
		return (NULL);
	(void)ft_strlcpy(str, &s1[firstpos], size);
	return (str);
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	char *a = ft_strtrim(av[1], " ");
	printf("%s --> %s\n",av[1],a);
	free(a);
	return (0);
}
*/