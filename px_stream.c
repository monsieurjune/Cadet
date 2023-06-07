/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_stream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:48:51 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/07 14:56:47 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_open(const char *path, int oflag, unsigned int mode, const char *msg)
{
	int	fd;

	(void)msg;
	fd = open(path, oflag, mode);
	if (fd == -1)
	{
		ft_putstr_fd(msg, STDERR_FILENO, msg);
		ft_putstr_fd(": ", STDERR_FILENO, msg);
		ft_putstr_fd(path, STDERR_FILENO, msg);
		ft_putstr_fd(": ", STDERR_FILENO, msg);
		perror("");
	}
	return (fd);
}

int	px_close(int fd, const char *msg)
{
	int	err;

	(void)msg;
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

	fd = dup2(oldfd, newfd);
	if (fd == -1)
	{
		perror(msg);
		return (fd);
	}
	return (fd);
}