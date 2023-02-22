/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:05:46 by tponutha          #+#    #+#             */
/*   Updated: 2022/10/09 20:52:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s0, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = s0[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

char	*ft_strcat(char *s0, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (*s1 || *s2)
	{
		if (*s1 != 0)
		{
			s0[i] = *s1;
			s1++;
		}
		else
		{
			s0[i] = *s2;
			s2++;
		}
		i++;
	}
	s0[i] = 0;
	return (s0);
}
