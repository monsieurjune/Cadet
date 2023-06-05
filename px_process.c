/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:35:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 22:16:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_cmd_check(char *cmd, const char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strclen(cmd, 0);
	if (ft_strnchr(&cmd[i], len, '/') == NULL)
		return ;
	if (access(cmd, X_OK) == -1)
		perror(msg);
}

/* CHILD PROCESS
1: close all unused pipe
2: flush all unused memory
3: dup2 to pipe that use
*/

void	sb_child_process(t_pipex *info, char **cmd)
{
	
}

/*
INSTRUCTION
1: allocate cmd
2: check access
3: forking
4: if parent then free cmd 
*/

void	px_calling_child(t_pipex *info)
{
	char	**cmd;
	int		i;
	int		pid;

	i = 0;
	while (i < info->clen)
	{
		cmd = px_ultra_split(info->av[i + 2 + (info->infile == 0)], info);
		if (cmd == NULL)
			perror(info->shell);
		else
			px_cmd_check(cmd[0], info->shell);
		pid = px_fork(info->shell);
		if (pid == 0)
			return ; // run child
		else
		{
			lm_free(cmd, &info->head);
			info->child_pid[i] = pid;
		} 
		i++;
	}
	// close all pipes
	// big wait function
}