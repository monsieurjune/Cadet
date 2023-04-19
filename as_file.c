/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 05:20:51 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:28:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astable.h"

int	as_open(t_data data, const char *path, int flag)
{
	int	fd;

	fd = open(path, flag);
	if (fd == -1)
		return (-1);
	data.table[fd] = 1;
	return (fd);
}

int	as_close(t_data data, int fd)
{
	int	err;

	if (data.table[fd] == 0)
		return (0);
	data.table[fd] = 0;
	err = close(fd);
	if (err == -1)
		perror("Closing File Error : ");
	return (err);
}

void	as_close_all(t_data data)
{
	int	i;
	int	err;

	i = 3;
	while (i <= OPEN_MAX)
	{
		(void)as_close(data, i);
		i++;
	}
}