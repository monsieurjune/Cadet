/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 06:11:29 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 18:27:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*
#include <stdio.h>
int main()
{
	char *a = "00000000000000";
	printf("%s\n",a);
	ft_striteri(a, ax);
	printf("%s\n",a);
	return (0);
}
*/