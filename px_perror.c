/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:03:43 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/08 10:08:54 by tponutha         ###   ########.fr       */
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

static char	*sb_half_msg(t_pipex *info, char *s, int len)
{
	char	*msg1;
	char	*msg2;
	char	*msg;

	
	msg1 = ft_strjoin(info->shell, ": ", &info->head);
	if (msg1 == NULL)
		return (NULL);
	msg2 = ft_strndup(s, len, &info->head);
	if (msg2 == NULL)
		return (lm_free(msg1, &info->head), NULL);
	msg = ft_strjoin(msg1, msg2, &info->head);
	lm_free(msg1, &info->head);
	lm_free(msg2, &info->head);
	return (msg);
}

void	px_cmd_perror(t_pipex *info, char *s)
{
	int		len;
	char	*msg1;
	char	*msg2;

	len = 0;
	while (s[len] == ' ' && s[len] != 0)
		len++;
	while (s[len] != ' ' && s[len] != 0)
		len++;
	if (ft_strnchr(s, len, '/') != NULL)
		return ;
	msg1 = sb_half_msg(info, s, len);
	if (msg1 == NULL)
		return (perror(info->shell));
	msg2 = ft_strjoin(msg1, ": command not found\n", &info->head);
	if (msg2 == NULL)
	{
		lm_free(msg1, &info->head);
		return (perror(info->shell));
	}
	ft_putstr_fd(msg2, STDERR_FILENO, info->shell);
	lm_free(msg1, &info->head);
	lm_free(msg2, &info->head); 
}

void	px_path_perror(t_pipex *info, const char *path)
{
	char	*msg1;
	char	*msg2;
	char	*msg;

	msg1 = ft_strjoin(info->shell, ": ", &info->head);
	if (msg1 == NULL)
		return (perror(info->shell));
	msg2 = ft_strjoin(path, ": ", &info->head);
	if (msg2 == NULL)
		return (perror(info->shell), lm_free(msg1, &info->head));
	msg = ft_strjoin(msg1, msg2, &info->head);
	lm_free(msg1, &info->head);
	lm_free(msg2, &info->head);
	if (msg == NULL)
		return (perror(info->shell));
	perror(msg);
	lm_free(msg, &info->head);
}

/*
< infile cat | lss |  sleep 1 | catd | cat | ./cmd1 > memod; echo $?
./pipex  infile cat lss  'sleep 1' catd cat ./cmd1 memod; echo $?

bash: lss: command not found
bash: catd: command not found
bash: infile: No such file or directory
bash: ./cmd1: No such file or directory
127
*/