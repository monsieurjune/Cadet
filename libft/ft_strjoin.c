/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:13:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 18:02:42 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, t_list **head)
{
	char	*str;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_malloc(sizeof(char), size, head);
	if (!str)
		return (NULL);
	(void)ft_strlcpy(str, s1, size);
	(void)ft_strlcat(str, s2, size);
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	(void)ac;
	char *a = ft_strjoin(NULL, av[2]);
	printf("%s + %s = %s\n",av[1],av[2],a);
	printf("%d\n", strcmp(a, "42"));
	free(a);
	return (0);
}
*/
