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

static void	sb_check_file(char *infile, char *outfile)
{
	if (infile != NULL)
	{
		if (access(infile, R_OK) == -1)
			perror("Input File Error : ");
	}
	if (access(infile, R_OK) == -1)
	{
		perror("Output File Error : ");
		exit(EXIT_FAILURE);
	}	
}

static void	sb_heredoc(t_data *data, int ac, char **av, char **envp)
{
	int	fd_out;
	
	sb_check_file(NULL, av[ac - 1]);
	fd_out = as_open(*data, av[ac - 1], O_WRONLY);
	ft_errno_logic(fd_out, data, "Output File Error : ");
	//
}

static void	sb_infile(t_data *data, int ac, char **av, char **envp)
{
	int	fd_in;
	int	fd_out;
	
	sb_check_file(av[1], av[ac - 1]);
	fd_in = as_open(*data, av[1], O_RDONLY);
	ft_errno_logic(fd_out, data, "Input File Error : ");
	fd_out = as_open(*data, av[ac - 1], O_WRONLY);
	ft_errno_logic(fd_out, data, "Output File Error : ");
	//
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac <= 1)
		return (0);
	data = as_init();
	if (ft_strncmp(av[1], "here_doc", sizeof("here_doc")) == 0)
		sb_heredoc(&data, ac, av, envp);
	else
		sb_infile(&data, ac, av, envp);
	return (as_flush_data(&data));
}