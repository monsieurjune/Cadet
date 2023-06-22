/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:12:04 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/13 05:25:43 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
}

/*
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("test.txt", O_RDWR);
	ft_putchar_fd('A', fd);
	close(fd);
	return (0);
}
*/