/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:35:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/06 22:16:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	WAIT FOR IMPROVE ERROR-HANDLEING	*/



static void	sb_handle_pipe_err(t_pipex *info, int use[])
{
	px_close(use[0], info->shell);
	px_close(use[1], info->shell);
	lm_flush(&info->head);
	exit(EXIT_SUCCESS);
}

/*	WAIT FOR IMPROVE ERROR-HANDLEING	*/

static void	sb_write_outfile(t_pipex *info, char **cmd, int i)
{
	int	use[2];
	int	r;
	int	w;
	int	e;

	px_close_pipe_except(info, i, -1, use);
	r = px_dup2(use[0], STDIN_FILENO, info->shell);
	w = px_dup2(info->outfile, STDOUT_FILENO, info->shell);
	if (r == use[0] || w == use[1] || cmd == NULL)
		sb_handle_pipe_err(info, use);
	else
	{
		e = execve(cmd[0], cmd, info->env);
		lm_flush(&info->head);
		exit(e);
	}
}

/* CHILD PROCESS
1: close all unused pipe
2: flush all unused memory
3: dup2 to pipe that use
*/

// read from pipe[i]
// write to pipe[i + 1]

static void	sb_child_process(t_pipex *info, char **cmd, int i, int clen)
{
	int	use[2];
	int	w;
	int	r;
	int	e;

	if (i < clen)
	{
		px_close_pipe_except(info, i, i + 1, use);
		px_close(info->outfile, info->shell);
		r = px_dup2(use[0], STDIN_FILENO, info->shell);
		w = px_dup2(use[1], STDOUT_FILENO, info->shell);
		if (r == use[0] || w == use[1] || cmd == NULL)
			sb_handle_pipe_err(info, use);
		e = execve(cmd[0], cmd, info->env);
		lm_flush(&info->head);
		exit(e);
	}
	else
		sb_write_outfile(info, cmd, i);
}

void	sb_big_wait(t_pipex *info)
{
	int	i;
	int	e;
	int	stat;

	i = 0;
	px_close_pipe_except(info, -1, -1, NULL);
	while (i < info->clen)
	{
		e = px_waitpid(info->child_pid[i], &stat, WUNTRACED, info->shell);
		if (e == -1)
		{
			perror(info->shell);
		}
		if (stat != 0)
			perror(info->shell);
		i++;
	}
	lm_flush(&info->head);
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
		else if (i == info->clen - 1)
			info->outfile = px_open(info->av[info->ac - 1], info->outflag,\
			 0644, info->shell);
		else
			px_cmd_check(cmd[0], info->shell);
		pid = px_fork(info->shell);
		if (pid == 0)
			return (sb_child_process(info, cmd, i, info->clen));
		else
		{
			lm_free(cmd, &info->head);
			info->child_pid[i] = pid;
		}
		i++;
	}
	sb_big_wait(info);
}