/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:42:51 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:20:26 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_errno_logic(int err, t_data *data, const char *str)
{
	if (err == -1)
		as_error_exit(data, str);
}