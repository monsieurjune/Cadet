/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:04:17 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 04:17:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sb_read_infile(t_pipex *info, char **cmd, int extra)
{
	int	e;
	int	in;

	if (extra == -1)
		in = px_open(info->av[1], O_RDONLY, 0, info);
	else
		in = extra;
	if (in != -1)
	{
		e = px_double_dup(cmd[0], in, info->pbox[1][1], info);
		e &= px_cmd_check(cmd[0], info);
		px_close_pipe(info);
		px_close(in, info->shell);
		if (e)
			execve(cmd[0], cmd, info->env);
	}
	lm_flush(&info->head);
	px_exit(in);
}

static void	sb_write_outfile(t_pipex *info, char **cmd, int i)
{
	int	oflag;
	int	out;
	int	e;

	if (info->start != 3)
		oflag = O_WRONLY | O_CREAT | O_TRUNC;
	else
		oflag = O_WRONLY | O_CREAT | O_APPEND;
	out = px_open(info->av[info->ac - 1], oflag, 0644, info);
	if (out != -1)
	{
		e = px_double_dup(cmd[0], info->pbox[i][0], out, info);
		e &= px_cmd_check(cmd[0], info);
		px_close_pipe(info);
		px_close(out, info->shell);
		if (e)
			execve(cmd[0], cmd, info->env);
	}
	lm_flush(&info->head);
	px_exit(out);
}

static void	sb_child_process(t_pipex *info, char **cmd, int i, int extra)
{
	int	e;

	if (i == 0)
		return (sb_read_infile(info, cmd, extra));
	else if (i == info->cmd_len - 1)
		return (sb_write_outfile(info, cmd, i));
	else
	{
		e = px_double_dup(cmd[0], info->pbox[i][0], info->pbox[i + 1][1], info);
		e &= px_cmd_check(cmd[0], info);
		px_close_pipe(info);
		if (e)
			execve(cmd[0], cmd, info->env);
		lm_flush(&info->head);
		px_exit(1);
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
			if (e != -1)
				errno = WEXITSTATUS(stat) % 255;
		}
		i++;
	}
}

void	px_calling_child(t_pipex *info, int extra)
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
			if (cmd == NULL && errno != 0)
				perror(info->shell);
			return (sb_child_process(info, cmd, i, extra));
		}
		else
			info->child[i] = pid;
		i++;
	}
	px_close_pipe(info);
	sb_big_wait(info);
	lm_flush(&info->head);
}
