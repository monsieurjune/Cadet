/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:40:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/07 13:05:12 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	px_pipex_first_init(&info, ac, av, env);
	px_pipex_second_init(&info, ft_strncmp(av[1], "here_doc", 8));
	px_calling_child(&info);
	return (0);
}

/*
int	main(int ac, char **av, char **envp)
{
	int i = 0;
	while (i < info.cmd_len)
	{
		printf("%d - %d\n", info.pbox[i][0], info.pbox[i][1]);
		close(info.pbox[i][0]);
		close(info.pbox[i][1]);
		i++;
	}
	lm_flush(&info.head);

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