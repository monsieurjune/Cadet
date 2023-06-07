/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:46:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/06 22:51:10 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_open(const char *path, int oflag, unsigned int mode, const char *msg)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd == -1)
		perror(msg);
	return (fd);
}

int	px_close(int fd, const char *msg)
{
	int	err;

	if (fd == -1)
		return (-1);
	err = close(fd);
	if (err == -1)
		perror(msg);
	return (err);
}

int	px_fork(const char *msg)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror(msg);
	return (pid);
}

int	px_waitpid(int pid, int *stat, int option, const char *msg)
{
	int	id;

	id = waitpid(pid, stat, option);
	if (id == -1)
		return (perror(msg), -1);
	return (id);
}

int	px_dup2(int oldfd, int newfd, const char *msg)
{
	int	fd;

	// (void)msg;
	// printf("%d : %d\n", oldfd, newfd);
	fd = dup2(oldfd, newfd);
	if (fd == -1)
	{
		perror(msg);
		return (oldfd);
	}
	px_close(oldfd, msg);
	return (fd);
}