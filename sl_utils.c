/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:05:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/26 18:52:26 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_open(char *path, int option)
{
	int	fd;

	fd = open(path, option);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Map Error : ", STDERR_FILENO);
		ft_putendl_fd(path, STDERR_FILENO);
	}
	return (fd);
}

void	sl_print_error(char *second)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(second, STDERR_FILENO);
}

void	sl_exit(t_list **head, int status)
{
	ft_flush(head);
	exit(status);
}