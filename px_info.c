/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 06:09:58 by tponutha         ###   ########.fr       */
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

static char	*sb_cat_path(const char *cmd, int n, t_pipex *info)
{
	int		i;
	char	*path;

	i = 0;
	if (ft_strnchr(cmd, n, '/') != NULL || cmd[0] == 0)
		return (ft_strndup(cmd, n, &info->head));
	while (info->paths[i] != NULL)
	{
		path = ft_threemany(info->paths[i], cmd, n, &info->head);
		if (path == NULL)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		lm_free(path, &info->head);
		i++;
	}
	return (ft_strndup(cmd, n, &info->head));
}

// Proved to work

char	**px_ultra_split(const char *s, t_pipex *info)
{
	char	**box;
	char	**temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i++] == ' ' && s[i] != 0);
	while (s[i++] != ' ' && s[i] != 0);
	temp = ft_split_cmd(&s[i], ' ', &info->head);
	if (temp == NULL)
		return (perror(info->shell), NULL);
	while (temp[len++] != NULL);
	box = lm_malloc(sizeof(char *), len + 2, &info->head);
	if (box == NULL)
		return (perror(info->shell), NULL);
	box[0] = sb_cat_path(s, i - 1, info);
	if (box[0] == NULL)
		return (perror(info->shell), NULL);
	i = 1;
	while (i < len + 1)
	{
		box[i] = temp[i - 1];
		i++;
	}
	return (box[i] = NULL, lm_free(temp, &info->head), box);
}

/* BUFFER OVERFLOW ?
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

// int	*px_child_box()
// {
// 	ac - 3 - (infile = 0);
// }

/*
- here doc treat access non-linear
- normal might treat access linear?
- if infile no access then don't print first cmd
- if outfile no access then 
*/

// Don't use this with here_doc
// Only print error if its not env path
/*
void	px_access_cmd(t_pipex info)
{
	int	i;
	int	err;

	if (info.infile == 0)
		return ;
	i = 2;
	while (i < info.ac - 1)
	{
		if (ft_strncmp(info.av[i], HOME_PATH, sizeof(HOME_PATH)) == 0 ||\
			ft_strncmp(info.av[i], ROOT_PATH, sizeof(ROOT_PATH)) == 0 ||\
			ft_strncmp(info.av[i], CURRENT_PATH, sizeof(CURRENT_PATH)) == 0 ||\
			ft_strncmp(info.av[i], PARENT_PATH, sizeof(PARENT_PATH)) == 0)
			if (access(info.av[i], X_OK))
				perror(info.shell);
		i++;
	}
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int	main(int ac, char **av, char **env)
{
	int 		i = 2;
	int			j;
	size_t		n;
	char		*str;
	char		**box;
	t_pipex		info;

	px_pipex_init(&info, ac, av, env);
	px_pipex_init2(&info, ft_strncmp(av[1], "here_doc", 8));
	while (i < ac - 1)
	{
		j = 0;
		//printf("%s\n", av[i]);
		box = px_ultra_split(av[i], &info);
		printf("split : ");	
		while (box[j] != NULL)
		{
			printf("%s, ", box[j]);
			j++;
		}
		printf("\n");
		lm_free(str, &info.head);
		i++;
	}
	lm_flush(&info.head);
	return (0);
}
