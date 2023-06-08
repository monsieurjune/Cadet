/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:12:46 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 04:18:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	sb_read_stdin(t_pipex *info, int use[])
{
	char	*line;
	int		lim_len;
	int		len;

	lim_len = ft_strclen(info->av[2], 0);
	line = get_next_line(STDIN_FILENO, &info->head);
	while (line != NULL)
	{
		len = ft_strclen(line, '\n');
		if (len == lim_len)
			if (ft_strncmp(line, info->av[2], len) == 0)
				break ;
		ft_putstr_fd(line, use[1], info->shell);
		lm_free(line, &info->head);
		line = get_next_line(STDIN_FILENO, &info->head);
	}
	close(use[1]);
	if (line == NULL && errno == ENOMEM)
	{
		perror(info->shell);
		lm_flush(&info->head);
		exit(EXIT_FAILURE);
	}
	return (use[0]);
}

int	px_heredoc(t_pipex *info, int start)
{
	int	use[2];

	if (start != 0)
		return (-1);
	if (pipe(use) == -1)
	{
		perror(info->shell);
		lm_flush(&info->head);
		exit(EXIT_FAILURE);
	}
	return (sb_read_stdin(info, use));
}
