/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ultra_spilt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:43:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 23:50:38 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char	**sb_assign_temp(t_pipex *info, const char *s, int *i, int *len)
{
	char	**temp;

	*i = 0;
	*len = 0;
	while (s[*i] == ' ' && s[*i] != 0)
		(*i)++;
	while (s[*i] != ' ' && s[*i] != 0)
		(*i)++;
	temp = ft_split_cmd(&s[*i], ' ', &info->head);
	if (temp == NULL)
		return (perror(info->shell), NULL);
	while (temp[*len] != NULL)
		(*len)++;
	return (temp);
}

char	**px_ultra_split(const char *s, t_pipex *info)
{
	char	**box;
	char	**temp;
	int		i;
	int		len;

	temp = sb_assign_temp(info, s, &i, &len);
	if (temp == NULL)
		return (perror(info->shell), NULL);
	box = lm_malloc(sizeof(char *), len + 2, &info->head);
	if (box == NULL)
		return (perror(info->shell), NULL);
	box[0] = sb_cat_path(s, i, info);
	if (box[0] == NULL)
		return (perror(info->shell), NULL);
	i = 1;
	while (i < len + 1)
	{
		box[i] = temp[i - 1];
		i++;
	}
	box[i] = NULL;
	lm_free(temp, &info->head);
	return (box);
}

// // here_doc infile 'cat -e' 'ls -l -a -t' 'rm -r -f' ./cmd1 '     ./cmd2'
// // " "
// // "" "abhscjjgya bjkbalwkbf jhwrjygkka jkvwkjyf" cat r rm man python3 
// // "outfile"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void print_mem(t_mem *head)
{
	if (head == NULL)
		return ;
	while (head->next != NULL)
	{
		printf("(%p) : %p\n", head, head->mem);
		head = head->next;
	}
}

int	main(int ac, char **av, char **env)
{
	int 		i = 2;
	int			j;
	size_t		n;
	char		*str;
	char		**box;
	t_pipex		info;

	info.head = NULL;
	px_pipex_init(&info, ac, av, env);
	//px_pipex_init2(&info, ft_strncmp(av[1], "here_doc", 8));
	printf("PARENT\n");
	print_mem(info.head);
	int pid = fork();
	if (pid == 0)
	{
		printf("\n");
		while (i < ac - 1)
		{
			j = 0;
			//printf("%s\n", av[i]);
			box = px_ultra_split(av[i], &info);
			//printf("split (%s)		: ", av[i]);
			while (box[j] != NULL)
			{
				//printf("%s, ", box[j]);
				lm_free(box[j], &info.head);
				j++;
			}
			//printf("\n");
			lm_free(box, &info.head);
			i++;
		}
		printf("CHILD\n");
		print_mem(info.head);
		lm_flush(&info.head);
		char *cmd[] = {"/bin/lss", NULL};
		int e = execve("/bin/lsa", cmd, env);
		exit(0);
	}
	else
	{
		int k;
		wait(&k);
		//lm_flush(&info.head);
		// printf("EXIT : %d\n", k);
		// printf("PATH : %s\n", info.paths[0]);
	}
	return (0);
}
