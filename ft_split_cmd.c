/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:51:59 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 05:08:42 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Proved to work
/*
TEST CASE
1:	'"" ""'
2:	'"a"" """'
3:	'"""" """"'
4:	'"a"a" """""'
5:	'cat -e'
6:	'a "  bhbw   dafb" "naflfa"'
*/

static size_t	sb_strlen_cmd(const char *s, char c)
{
	size_t	count;
	size_t	len;

	len = 0;
	count = 0;
	while (s[len] != 0 && (s[len] != c || count % 2 != 0))
	{
		count += (s[len] == '\x27' || s[len] == '"');
		len++;
	}
	return (len);
}

// Proved to work

static char	*sb_strdup_cmd(const char *s, char c, t_mem **head)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = sb_strlen_cmd(s, c);
	str = lm_malloc(sizeof(char), len + 1, head);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**sb_alloc_box(const char *s, char c, size_t len, t_mem **head)
{
	char	flag;
	char	**box;
	size_t	count;
	size_t	n;

	box = lm_malloc(sizeof(char *), len + 1, head);
	n = 0;
	count = 0;
	flag = 1;
	while (*s && box != NULL)
	{
		if (flag && *s != c)
		{
			box[n] = sb_strdup_cmd(s, c, head);
			if (box[n] == NULL)
				return (NULL);
			n += flag--;
		}
		else if (!flag && *s == c)
			flag = 1;
		count += (s[len] == '\x27' || s[len] == '"');
		s++;
	}
	return (box);
}

// Proved to work

char	**ft_split_cmd(char const *s, char c, t_mem **head)
{
	char	flag;
	char	**box;
	size_t	len;
	size_t	i;
	size_t	count;

	if (!s || !s[0])
		return (lm_calloc(sizeof(char *), 1, head));
	flag = 1;
	len = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (flag && s[i] != c)
			len += flag--;
		else if (!flag && s[i] == c)
			flag = 1;
		count += (s[len] == '\x27' || s[len] == '"');
		i++;
	}
	box = sb_alloc_box(s, c, len, head);
	if (box != NULL)
		box[len] = NULL;
	return (box);
}

/*
char	**ft_ultra_split(char const *s, char c, t_mem **head)
{
	size_t	i;
	char	**temp;
	char	**res;

	i = 0;
	while (s[i] == ' ' || s[i] != 0)
		i++;
	temp = ft_split_cmd(&s[i], );
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int	main(int ac, char **av)
{
	int 	i = 1;
	int		j;
	size_t	n;
	char	*str;
	char	**box;
	t_mem	*head = NULL;

	while (i < ac)
	{
		n = sb_strlen_cmd(av[i], ' ');
		str = ft_strdup_cmd(av[i], ' ', &head);
		printf("strlen: (%s) = %ld\n", av[i], n);
		j = 0;
		box = ft_split_cmd(av[i], ' ', &head);
		printf("split: ");
		while (box[j] != NULL)
		{
			printf("%s | ", box[j]);
			j++;
		}
		printf("\n");
		lm_free(str, &head);
		i++;
	}
	lm_flush(&head);
	return (0);
}
*/
