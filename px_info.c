/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/02 20:28:24 by tponutha         ###   ########.fr       */
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

int	sb_pipex_init(t_pipex *info, int ac, char **av, char **env)
{
	char	*env_path;
	char	*env_shell;
	
	env_path = sb_search_env(env, "PATH");
	env_shell = sb_search_env(env, "SHELL");
	info->ac = ac;
	info->av = av;
	info->env = env;
	info->head = NULL;
	info->shell = ft_strrchr(env_shell, '/');
	info->pipebox = NULL;
	info->child_pid = NULL;
	info->paths = ft_split_cmd(env_path, ':', &info->head);
	if (info->paths == NULL)
	{
		perror(info->shell);
		return (1);
	}
	return (0);
}



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