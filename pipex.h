/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:37:50 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/05 20:51:42 by tponutha         ###   ########.fr       */
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

# ifndef HOME_PATH
#  define HOME_PATH "~/"
# endif

# ifndef ROOT_PATH
#  define ROOT_PATH "/"
# endif

# ifndef CURRENT_PATH
#  define CURRENT_PATH "./"
# endif

# ifndef PARENT_PATH
#  define PARENT_PATH "../"
# endif

# ifndef EXEVE_ERR
#  define EXEVE_ERR	""
# endif

typedef struct s_pipex
{
	int				ac;
	char			**av;
	char			**env;
	int				infile;
	int				outfile;
	char			*shell;
	char			**paths;
	int				**pipebox;
	int				plen;
	int				*child_pid;
	int				clen;
	struct s_mem	*head;
}	t_pipex;

/*		px_child_info_bonus.c	*/
int		**px_allocate_pipe(t_pipex *info);

/**/
int		px_open(const char *path, int oflag, unsigned int mode, const char *msg);
int		px_close(int fd, const char *msg);
int		px_fork(const char *msg);
int		px_waitpid(int pid, int *stat, int option, const char *msg);

/**/
int		px_pipex_init(t_pipex *info, int ac, char **av, char **env);
int		px_pipex_init2(t_pipex *info, int infile);

/**/
char	**px_ultra_split(const char *s, t_pipex *info);

#endif