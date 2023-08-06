/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ultra_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:43:53 by tponutha          #+#    #+#             */
/*   Updated: 2023/08/07 01:04:12 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*sb_cat_path(const char *cmd, int n, t_pipex *info)
{
	int		i;
	char	*path;
	int		err;

	i = 0;
	err = errno;
	if (ft_strnchr(cmd, n, '/') != NULL || cmd[0] == 0)
		return (ft_strndup(cmd, n, &info->head));
	while (info->paths[i] != NULL)
	{
		path = ft_threemany(info->paths[i], cmd, n, &info->head);
		if (path == NULL)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (errno = err, path);
		lm_free(path, &info->head);
		i++;
	}
	errno = err;
	return (ft_strndup(cmd, n, &info->head));
}

static char	**sb_assign_temp(t_pipex *info, const char *s, int *i, int *len)
{
	char	**temp;

	if (s == NULL)
		return (lm_calloc(sizeof(char), 1, &info->head));
	*i = 0;
	*len = 0;
	while (s[*i] == ' ' && s[*i] != 0)
		(*i)++;
	while (s[*i] != ' ' && s[*i] != 0)
		(*i)++;
	temp = ft_split_cmd(&s[*i], ' ', &info->head);
	if (temp == NULL)
		return (NULL);
	while (temp[*len] != NULL)
		(*len)++;
	return (temp);
}

static char	*sb_remove_quote(char *s)
{
	size_t	len[2];
	size_t	offset;
	char	*str;

	len[0] = ft_strclen(s, 0);
	if (ft_strnchr(s, len[0], '\x27') > ft_strnchr(s, len[0], '"'))
		str = ft_strnchr(s, len[0], '\x27');
	else
	 	str = ft_strnchr(s, len[0], '"');
	if (str == NULL)
		str = s;
	else
	 	str++;
	len[1] = ft_strclen(str, 0);
	offset = len[0] - len[1];
	str[len[1] - offset] = 0;
	return (str);
}

char	**px_ultra_split(const char *s, t_pipex *info)
{
	char	**box;
	char	**temp;
	int		i;
	int		len;

	temp = sb_assign_temp(info, s, &i, &len);
	if (temp == NULL)
		return (NULL);
	box = lm_malloc(sizeof(char *), len + 2, &info->head);
	if (box == NULL)
		return (NULL);
	box[0] = sb_cat_path(s, i, info);
	if (box[0] == NULL)
		return (NULL);
	i = 1;
	while (i < len + 1)
	{
		box[i] = sb_remove_quote(temp[i - 1]);
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

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// void print_mem(t_mem *head)
// {
// 	if (head == NULL)
// 		return ;
// 	while (head->next != NULL)
// 	{
// 		printf("(%p) : %p\n", head, head->mem);
// 		head = head->next;
// 	}
// }

// int	main(int ac, char **av, char **env)
// {
// 	int 		i = 2;
// 	int			j;
// 	size_t		n;
// 	char		*str;
// 	char		**box;
// 	t_pipex		info;

// 	info.head = NULL;
// 	px_pipex_init(&info, ac, av, env);
// 	//px_pipex_init2(&info, ft_strncmp(av[1], "here_doc", 8));
// 	printf("PARENT\n");
// 	print_mem(info.head);
// 	int pid = fork();
// 	if (pid == 0)
// 	{
// 		printf("\n");
// 		while (i < ac - 1)
// 		{
// 			j = 0;
// 			//printf("%s\n", av[i]);
// 			box = px_ultra_split(av[i], &info);
// 			//printf("split (%s)		: ", av[i]);
// 			while (box[j] != NULL)
// 			{
// 				//printf("%s, ", box[j]);
// 				lm_free(box[j], &info.head);
// 				j++;
// 			}
// 			//printf("\n");
// 			lm_free(box, &info.head);
// 			i++;
// 		}
// 		printf("CHILD\n");
// 		print_mem(info.head);
// 		lm_flush(&info.head);
// 		char *cmd[] = {"/bin/lss", NULL};
// 		int e = execve("/bin/lsa", cmd, env);
// 		exit(0);
// 	}
// 	else
// 	{
// 		int k;
// 		wait(&k);
// 		//lm_flush(&info.head);
// 		// printf("EXIT : %d\n", k);
// 		// printf("PATH : %s\n", info.paths[0]);
// 	}
// 	return (0);
// }
