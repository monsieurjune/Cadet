/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 20:18:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	**sb_assign_pipe(t_pipex *info)
{
	int	i;
	int	err_i;

	i = 0;
	while (i < info->cmd_len)
	{
		if (pipe(info->pbox[i]) == -1)
		{
			perror(info->shell);
			err_i = i;
			break ;
		}
		i++;
	}
	if (i == info->cmd_len)
		return (info->pbox);
	i = 0;
	while (i < err_i)
	{
		px_close(info->pbox[i][0], info->shell);
		px_close(info->pbox[i][1], info->shell);
		i++;
	}
	return (NULL);
}

static int	**sb_allocate_pipe(t_pipex *info)
{
	int	i;

	info->pbox = lm_malloc(sizeof(int *), info->cmd_len, &info->head);
	if (info->pbox == NULL)
		return (perror(info->shell), NULL);
	i = 0;
	while (i < info->cmd_len)
	{
		info->pbox[i] = lm_malloc(sizeof(int), 2, &info->head);
		if (info->pbox[i] == NULL)
			return (perror(info->shell), NULL);
		i++;
	}
	return (sb_assign_pipe(info));
}

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

void	px_pipex_second_init(t_pipex *info, int cmp)
{
	info->start = 2;
	if (cmp == 0)
		info->start = 3;
	info->cmd_len = info->ac - 3 - (info->start == 3);
	info->child = lm_malloc(sizeof(int), info->cmd_len, &info->head);
	if (info->child == NULL)
	{
		perror(info->shell);
		lm_flush(&info->head);
		exit(EXIT_FAILURE);
	}
	info->pbox = sb_allocate_pipe(info);
	if (info->pbox == NULL)
	{
		perror(info->shell);
		lm_flush(&info->head);
		exit(EXIT_FAILURE);
	}
}

void	px_pipex_first_init(t_pipex *info, int ac, char **av, char **env)
{
	char	*env_shell;
	char	*env_path;

	env_shell = sb_search_env(env, "SHELL");
	env_path = sb_search_env(env, "PATH");
	info->ac = ac;
	info->av = av;
	info->env = env;
	info->head = NULL;
	info->shell = ft_strrchr(env_shell, '/') + 1;
	info->paths = ft_split_cmd(env_path, ':', &info->head);
	if (info->paths == NULL)
	{
		perror(info->shell);
		exit(EXIT_FAILURE);
	}
}

// void	px_cmd_check(char *cmd, const char *msg)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strclen(cmd, 0);
// 	if (ft_strnchr(&cmd[i], len, '/') == NULL)
// 		return ;
// 	if (access(cmd, X_OK) == -1)
// 		perror(msg);
// }

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