/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:04:17 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/07 15:06:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sb_read_infile(t_pipex *info, char **cmd)
{
	int	e;
	int	in;

	e = 0;
	in = px_open(info->av[1], O_RDONLY, 0, info->shell);
	if (in != -1)
	{
		if (px_dup2(in, STDIN_FILENO, info->shell) != -1 && \
			px_dup2(info->pbox[1][1], STDOUT_FILENO, info->shell) != -1 && \
			cmd != NULL)
		{
			px_close_pipe(info);
			e = execve(cmd[0], cmd, info->env);
		}
		else
		{
			px_close_pipe(info);
			perror(info->shell);
		}
		px_close(in, info->shell);
	}
	lm_flush(&info->head);
	exit(e);
}

static void	sb_write_outfile(t_pipex *info, char **cmd, int i)
{
	int	e;
	int	oflag;
	int	out;

	if (info->start != 3)
		oflag = O_WRONLY | O_CREAT | O_TRUNC;
	else
		oflag = O_WRONLY | O_CREAT | O_APPEND;
	out = px_open(info->av[info->ac - 1], oflag, 0644, info->shell);
	if (out != -1)
	{
		if (px_dup2(info->pbox[i][0], STDIN_FILENO, info->shell) != -1 && \
			px_dup2(out, STDOUT_FILENO, info->shell) != -1 && \
			cmd != NULL)
		{
			px_close_pipe(info);
			e = execve(cmd[0], cmd, info->env);
		}
		else
		{
			px_close_pipe(info);
			perror(info->shell);
		}
		px_close(out, info->shell);
	}
	lm_flush(&info->head);
	exit(e);
}

static void	sb_child_process(t_pipex *info, char **cmd, int i)
{
	int		e;

	e = 0;
	if (i == 0)
		return (sb_read_infile(info, cmd));
	else if (i == info->cmd_len - 1)
		return (sb_write_outfile(info, cmd, i));
	else
	{
		if (px_dup2(info->pbox[i][0], STDIN_FILENO, info->shell) != -1 && \
			px_dup2(info->pbox[i + 1][1], STDOUT_FILENO, info->shell) != -1 && \
			cmd != NULL)
		{
			px_close_pipe(info);
			e = execve(cmd[0], cmd, info->env);
		}
		else
		{
			px_close_pipe(info);
			perror(info->shell);
		}
		lm_flush(&info->head);
		exit(e);
	}
}

void	sb_big_wait(t_pipex *info)
{
	int	i;
	int	stat;
	int	e;

	i = 0;
	while (i < info->cmd_len)
	{
		if (info->child[i] != -1)
		{
			e = px_waitpid(info->child[i], &stat, WUNTRACED, info->shell);
			if (e != -1 && stat != 0)
				px_cmd_perror(info, info->av[info->start + i]);
		}
		i++;
	}
}

void	px_calling_child(t_pipex *info)
{
	int		i;
	int		pid;
	char	**cmd;

	i = 0;
	while (i < info->cmd_len)
	{
		pid = px_fork(info->shell);
		if (pid == 0)
		{
			cmd = px_ultra_split(info->av[info->start + i], info);
			if (cmd == NULL)
				perror(info->shell);
			else if (access(cmd[0], X_OK) == -1)
				px_path_perror(info, cmd[0]);
			return (sb_child_process(info, cmd, i));
		}
		else
			info->child[i] = pid;
		i++;
	}
	px_close_pipe(info);
	sb_big_wait(info);
	lm_flush(&info->head);
}