/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:37:50 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 00:13:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>

typedef struct s_pipex
{
	int				ac;
	char			**av;
	char			**env;
	int				start;
	char			*shell;
	char			**paths;
	int				**pbox;
	int				*child;
	int				cmd_len;
	struct s_mem	*head;
}	t_pipex;

/**/
int		px_open(const char *path, int oflag, unsigned int mode, t_pipex *info);
int		px_close(int fd, const char *msg);
int		px_fork(const char *msg);
int		px_waitpid(int pid, int *stat, int option, const char *msg);
int		px_dup2(int oldfd, int newfd, const char *msg);

/**/
void	px_pipex_first_init(t_pipex *info, int ac, char **av, char **env);
void	px_pipex_second_init(t_pipex *info, int cmp);

/**/
void	px_calling_child(t_pipex *info);

/**/
char	**px_ultra_split(const char *s, t_pipex *info);

void	ft_putstr_fd(const char *s, int fd, const char *msg);
void	px_cmd_perror(t_pipex *info, char *s);
void	px_path_perror(t_pipex *info, const char *path);

// void	px_close_pipe(t_pipex *info, int n);
void	px_close_pipe(t_pipex *info);

/**/
void	px_exit(int isexe);
int		px_cmd_check(char *cmd, t_pipex *info);
int		px_double_dup(char *cmd, int r, int w, t_pipex *info);

#endif