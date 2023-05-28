/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:40:35 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:35:17 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	
}

/*
int	main(int ac, char **av, char **envp)
{
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
}
*/