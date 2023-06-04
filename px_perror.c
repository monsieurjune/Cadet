/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:46:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 04:41:46 by tponutha         ###   ########.fr       */
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

// void	px_cmd_check(char *cmd, const char *msg)
// {
// 	int		i;

// 	i = 0;
// 	while (cmd[i] == ' ' || cmd[i] != 0)
// 		i++;
// 	if (ft_strchr(&cmd[i], '/') == NULL)
// 		return ;
// 	if (access(cmd, X_OK) == -1)
// 		perror(msg);
// }