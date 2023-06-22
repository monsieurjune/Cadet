/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:02:01 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/13 04:45:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd != -1)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			if (n < 0)
			{
				n *= -1;
				write(fd, "-", 1);
			}
			if (n >= 10)
				ft_putnbr_fd(n / 10, fd);
			write(fd, &"0123456789"[n % 10], 1);
		}
	}
}

/*
#include <fcntl.h>
int main(int ac, char **av)
{
	(void)ac;
	int fd;
	fd = open("test.txt", O_RDWR);
	ft_putnbr_fd(atoi(av[1]), fd);
	close(fd);
}
*/