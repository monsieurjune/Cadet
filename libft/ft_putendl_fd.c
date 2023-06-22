/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:31:44 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/13 06:22:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s && fd != -1)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}

/*
#include <fcntl.h>
#include <string.h>
int main()
{
	int fd = open("./test.txt", O_RDWR | O_CREAT);
	ft_putendl_fd("42", fd);
	char s[10] = {0};
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 4);
	write(1, s, 3);
	unlink("./test.txt");
	return (0);
}
*/