/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:28:48 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/06 11:21:09 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
