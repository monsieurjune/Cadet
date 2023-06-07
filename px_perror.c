/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:03:43 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/07 14:56:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(const char *s, int fd, const char *msg)
{
	size_t	len;

	if (s && fd != -1)
	{
		len = ft_strclen(s, 0);
		if (write(fd, s, len) == -1)
			perror(msg);
	}
}

void	px_close_pipe(t_pipex *info)
{
	int	i;

	i = 0;
	while (i < info->cmd_len)
	{
		px_close(info->pbox[i][0], info->shell);
		px_close(info->pbox[i][1], info->shell);
		i++;
	}
	lm_free(info->pbox[0], &info->head);
	lm_free(info->pbox, &info->head);
}

void	px_cmd_perror(t_pipex *info, char *s)
{
	int		len;

	len = 0;
	while (s[len] == ' ' && s[len] != 0)
		len++;
	while (s[len] != ' ' && s[len] != 0)
		len++;
	ft_putstr_fd(info->shell, STDERR_FILENO, info->shell);
	ft_putstr_fd(": ", STDERR_FILENO, info->shell);
	if (write(STDERR_FILENO, s, len) == -1)
			perror(info->shell);
	ft_putstr_fd(": command not found\n", STDERR_FILENO, info->shell);
	
}

void	px_path_perror(t_pipex *info, char *path)
{
	ft_putstr_fd(info->shell, STDERR_FILENO, info->shell);
	ft_putstr_fd(": ", STDERR_FILENO, info->shell);
	ft_putstr_fd(path, STDERR_FILENO, info->shell);
	ft_putstr_fd(": ", STDERR_FILENO, info->shell);
	perror("");
}