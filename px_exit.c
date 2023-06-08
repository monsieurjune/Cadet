/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:43:28 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 00:03:14 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
0 : success
1: file permission denied
126: cmd permission denied
127: no such file or directory
*/

void	px_exit(int isexe)
{
	if (errno == ENOENT)
		exit(127);
	if (errno == EACCES)
	{
		if (isexe != -1)
			exit(126);
		exit(1);
	}
	exit(0);
}

// if (ft_strrchr(cmd[0], '/') != NULL)
			// 	if (access(cmd[0], X_OK) == -1)
			// 		px_path_perror(info, cmd[0]);
			// if (ft_strrchr(cmd[0], '/') == NULL)
			// 	px_cmd_perror(info, cmd[0]);

int	px_cmd_check(char *cmd, t_pipex *info)
{
	if (ft_strrchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == -1)
		{
			px_path_perror(info, cmd);
			return (0);
		}
		return (1);
	}
	px_cmd_perror(info, cmd);
	return (0);
}

int	px_double_dup(char *cmd, int r, int w, t_pipex *info)
{
	int	e1;
	int	e2;

	e1 = px_dup2(r, STDIN_FILENO, info->shell);
	e2 = px_dup2(w, STDOUT_FILENO, info->shell);
	return (e1 != -1 && e2 != -1 && cmd != NULL);
}