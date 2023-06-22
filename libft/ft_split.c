/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:05:54 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 22:43:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	sub_issame(const char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

static char	**sub_failsafe(char **box, t_list **head)
{
	size_t	i;

	i = 0;
	while (box[i])
	{
		ft_free(box[i], head);
		i++;
	}
	ft_free(box[i], head);
	ft_free(box, head);
	return (NULL);
}

static char	**sub_box(const char *s, char c, size_t len, t_list **head)
{
	char	flag;
	char	**box;
	size_t	i;
	size_t	j;

	box = ft_calloc(len + 1, sizeof(char *), head);
	i = 0;
	j = 0;
	flag = 1;
	while (s[i] && box)
	{
		if (flag && s[i] != c)
		{
			box[j] = ft_strcdup(&s[i], c, head);
			if (!box[j])
				return (sub_failsafe(box, head));
			j += flag--;
		}
		else if (!flag && s[i] == c)
			flag = 1;
		i++;
	}
	return (box);
}

char	**ft_split(char const *s, char c, t_list **head)
{
	char	flag;
	size_t	len;
	size_t	i;

	if (!s || !s[0] || sub_issame(s, c))
		return (ft_calloc(1, sizeof(char *), head));
	flag = 1;
	len = 0;
	i = 0;
	while (s[i])
	{
		if (flag && s[i] != c)
			len += flag--;
		else if (!flag && s[i] == c)
			flag = 1;
		i++;
	}
	return (sub_box(s, c, len, head));
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	int i = 0;
	(void)ac;
	char **a = ft_split(av[1], av[2][0]);
	while (a[i])
	{
		printf("%d.) %s\n", i, a[i]);
		i++;
	}
	(void)sub_failsafe(a);
	return (0);
}
*/
