/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:10:11 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/07 00:11:28 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
/*
int main(int ac, char **av, char **envp)
{
    char    *a = malloc(20);
    char    *b = "Hello world";
    int    **c = malloc(16);
    int      *d = malloc(4);
    int      *e = malloc(4);
    c[0] = d;
    c[1] = e;
    d = NULL;
    e = NULL;

    a[19] = 0;
    strcpy(a, b);
    printf("%d\n", O_CREAT | O_RDWR);
    int i = fork();
    if (i == 0)
    {
        a[0] = 'L';
        //b[0] = 'K';
        printf("A : %s\n", a);
        printf("B : %s\n", b);
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("A : %s\n", a);
        printf("B : %s\n", b);
        exit(0);
    }
}
*/

// int main(int ac, char **av)
// {
//     int i = fork();
//     if (i == 0)
//         printf("OK\n");
//     else
//     {
//         wait(NULL);
//         printf("KO\n");
//     }
//     return (0);
// }


void ft_read(int in, int pi)
{
	char buff[1000];
	int r = read(in, buff, 1000);
	buff[r] = 0;
	int i = 0;
	while (buff[i] != 0)
	{
		write(pi, &buff[i], 1);
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
    char *test1[] = {"/bin/sleep", "10",NULL};
	char *test2[] = {"/bin/ls", "-l",NULL};
	char *test3[] = {"/bin/cat", "-e",NULL};
	char *test4[] = {"/bin/cat", "-e",NULL};
	
	int	child[4];
	int p1[2];
	int p2[2];
	int p3[2];
	int p4[2];

	pipe(p1);
	pipe(p2);
	pipe(p3);
	pipe(p4);

	int in = open("./infile", O_RDONLY);
	ft_read(in, p1[1]);
	int	out =  open("./outfile", O_WRONLY | O_TRUNC);

	close(in);
	int i = 0;
	int	e;
	int	pid;
	while (i < 4)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
			{
				// close(p1[0]);
				close(p1[1]);
				close(p2[0]);
				// close(p2[1]);
				close(p3[0]);
				close(p3[1]);
				close(p4[0]);
				close(p4[1]);
				close(out);

				dup2(p1[0], STDIN_FILENO);
				dup2(p2[1], STDOUT_FILENO);
				if (errno != 0)
					perror("ERROR1");

				close(p1[0]);
				close(p2[1]);
				e = execve(test1[0], test1, envp);
				exit(e);
			}
			else if (i == 1)
			{
				close(p1[0]);
				close(p1[1]);
				// close(p2[0]);
				close(p2[1]);
				close(p3[0]);
				// close(p3[1]);
				close(p4[0]);
				close(p4[1]);
				close(out);

				dup2(p2[0], STDIN_FILENO);
				dup2(p3[1], STDOUT_FILENO);
				if (errno != 0)
					perror("ERROR2");

				close(p2[0]);
				close(p3[1]);
				e = execve(test2[0], test2, envp);
				exit(e);
			}
			else if (i == 2)
			{
				
				close(p1[0]);
				close(p1[1]);
				close(p2[0]);
				close(p2[1]);
				// close(p3[0]);
				close(p3[1]);
				close(p4[0]);
				// close(p4[1]);
				close(out);

				dup2(p3[0], STDIN_FILENO);
				dup2(p4[1], STDOUT_FILENO);
				if (errno != 0)
					perror("ERROR3");

				close(p3[0]);
				close(p4[1]);
				e = execve(test3[0], test3, envp);
				exit(e);
			}
			else if (i == 3)
			{
				close(p1[0]);
				close(p1[1]);
				close(p2[0]);
				close(p2[1]);
				close(p3[0]);
				close(p3[1]);
				// close(p4[0]);
				close(p4[1]);
				// close(out);

				dup2(p4[0], STDIN_FILENO);
				dup2(out, STDOUT_FILENO);
				if (errno != 0)
					perror("ERROR4");

				close(p4[0]);
				close(out);
				e = execve(test4[0], test4, envp);
				exit(e);
			}
		}
		else
		{
			child[i] = pid;
		}
		i++;
	}

	close(p1[0]);
	close(p1[1]);
	close(p2[0]);
	close(p2[1]);
	close(p3[0]);
	close(p3[1]);
	close(p4[0]);
	close(p4[1]);
	close(out);
	
	int j = 0;
	while (j < 4)
	{
		waitpid(child[j], NULL, WUNTRACED);
		j++;
	}
	printf("Process Completed\n");
    return (0);
}
