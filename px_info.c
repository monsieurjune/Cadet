/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/06 13:56:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*sb_search_env(char **env, char *search)
{
	int		i;
	int		len;
	char	*find;

	i = 0;
	len = ft_strclen(search, 0);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], search, len) == 0)
		{
			len = ft_strclen(env[i], 0);
			find = ft_strnstr(env[i], "=", len);
			return (find + 1);
		}
		i++;
	}
	return (NULL);
}

int	px_pipex_init2(t_pipex *info, int infile)
{
	info->infile = infile;
	info->outflag = O_WRONLY | O_CREAT;
	info->outflag |= O_APPEND * (infile == 0) | O_TRUNC * (infile != 0);
	info->clen = info->ac - 3 - (info->infile == 0);
	info->child_pid = lm_malloc(sizeof(int), info->clen, &info->head);
	if (info->child_pid == NULL)
		return (perror(info->shell), lm_flush(&info->head), 1);
	info->pipebox = px_allocate_pipe(info);
	if (info->pipebox == NULL)
		return (perror(info->shell), lm_flush(&info->head), 1);
	return (0);
}

int	px_pipex_init(t_pipex *info, int ac, char **av, char **env)
{
	info->ac = ac;
	info->av = av;
	info->env = env;
	info->head = NULL;
	info->shell = ft_strrchr(sb_search_env(env, "SHELL"), '/') + 1;
	info->pipebox = NULL;
	info->child_pid = NULL;
	info->paths = ft_split_cmd(sb_search_env(env, "PATH"), ':', &info->head);
	if (info->paths == NULL)
		return (perror(info->shell), 1);
	return (0);
}

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

/* BUFFER OVERFLOW
char	**px_ultra_split(const char *s, int len, t_pipex *info)
{
	char	**box;
	char	**temp;
	int		i;

	i = 0;
	while (s[i++] == ' ' || s[i] != 0)
	while (s[i++] != ' ' || s[i] != 0)
	printf("%s\n", &s[i]);
	temp = ft_split_cmd(&s[i], ' ', &info->head);
	if (temp == NULL)
		return (perror(info->shell), NULL);
	while (temp[len++] != NULL)
	box = lm_malloc(sizeof(char *), len + 1, &info->head);
	if (box == NULL)
		return (perror(info->shell), NULL);
	box[0] = sb_cat_path(s, i - 1, info);
	if (box[0] == NULL)
		return (perror(info->shell), NULL);
	i = 1;
	while (i < len)
	{
		box[i] = temp[i];
		i++;
	}
	return (box[len] = NULL, lm_free(temp, &info->head), box);
}
*/