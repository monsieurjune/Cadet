/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:35:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 04:41:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		cmd = ft_split_cmd(info->av[i + 2 + (info->infile == 0)], ' ', &info->head);
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
	// close all pipes, close infile
	// big wait function
}