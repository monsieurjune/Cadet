/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:40:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/06 21:58:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr_fd(char *s, int fd, const char *msg)
{
	size_t	len;

	if (s && fd != -1)
	{
		len = ft_strclen(s, 0);
		if (write(fd, s, len) == -1)
			perror(msg);
	}
}


static void	sb_read_infile(t_pipex *info)
{
	char	*line;

	line = get_next_line(info->infile, &info->head);
	while (line != NULL)
	{
		ft_putstr_fd(line, info->pipebox[0][1], info->shell);
		lm_free(line, &info->head);
		line = get_next_line(info->infile, &info->head);
	}
	px_close(info->infile, info->shell);
}

/* PIPEX INSTRUCTION
1: allocate pipe
2: check here_doc or not
3: allocate cmd + args
4: check permission
5: open outfile
6: call child process
*/

int	main(int ac, char **av, char **env)
{
	t_pipex	info;

	if (ac < 5)
		return (EXIT_SUCCESS);
	if (px_pipex_init(&info, ac, av, env))
		return (EXIT_FAILURE);
	if (px_pipex_init2(&info, ft_strncmp(av[1], "here_doc", 8)))
		return (EXIT_FAILURE);
	if (info.infile == 0)
		info.infile = 0; /// check_here_doc
	else
		info.infile = px_open(av[1], O_RDONLY, 0, info.shell);
	if (info.infile != -1)
		sb_read_infile(&info);
	px_calling_child(&info);
	return (EXIT_SUCCESS);
}

/*
int	main(int ac, char **av, char **envp)
{
	printf("%s\n", sb_search_env(env, av[1]));
	int	j;
	int	pid;
	int fd[2];
	char str[2];

	j = 0;
	pipe(fd);
	write(fd[1], "A", 1);
	pid = fork();
	for (int i = 1; i < ac; i++)
	{
		if (pid == 0)
		{
			pid = fork();
			j++;
			if (pid != 0)
				break ;
		}
	}
	waitpid(pid, NULL, 0);
	if (pid == 0)
	{
		close(fd[0]);
		//write(fd[1], "A", 1);
		close(fd[1]);
	}
	else if (pid != 0)
	{
		read(fd[0], str, 1);
		str[1] = '\0';
		printf("I'm parent %d : doing -> %s (verfiy : %s)\n", pid, av[j], str);
		str[0]++;
		write(fd[1], str, 1);
		close(fd[0]);
		close(fd[1]);
	}
	//outfile = open(av[ac - 1], O_WRONLY | O_CREAT | \
					O_TRUNC * (infile != 0) | O_APPEND * (infile == 0), \
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}
*/