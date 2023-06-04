/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 06:59:09 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/04 22:35:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_close_pipe_except(t_pipex *info, int *r, int *w, int use[])
{
	int	i;

	i = 0;
	if (*r <= -1)
	{
		px_close(info->pipebox[i][1], info->shell);
		use[0] = info->pipebox[*r][0];
	}
	if (*w <= -1)
	{
		px_close(info->pipebox[i][0], info->shell);
		use[1] = info->pipebox[*w][1];
	}
	while (i < info->plen)
	{
		if (i != *r && i != *w)
		{
			px_close(info->pipebox[i][0], info->shell);
			px_close(info->pipebox[i][1], info->shell);
		}
		i++;
	}
	lm_free(info->pipebox[0], &info->head);
	lm_free(info->pipebox, &info->head);
}

static int	**sb_assign_pipe(t_pipex *info)
{
	int	i;
	
	i = 0;
	while (i < info->plen)
	{
		if (pipe(info->pipebox[i]) == -1)
			break ;
		i++;
	}
	if (i == info->plen)
		return (info->pipebox);
    i = i - 1;
	perror(info->shell);
	while (i >= 0)
	{
		px_close(info->pipebox[i][0], info->shell);
		px_close(info->pipebox[i][1], info->shell);
		i--;
	}
	return (lm_flush(&info->head), NULL);
}

/* ALLOCATE PIPE
	- if error, will close every pipes before return NULL
*/

int	**px_allocate_pipe(t_pipex *info)
{
	int	*pipedes;
	int	i;

	info->plen = info->ac - 2 - (info->infile == 0);
	i = 0;
	info->pipebox = lm_malloc(sizeof(int *), info->plen, &info->head);
	if (info->pipebox == NULL)
		return (perror(info->shell), lm_flush(&info->head), NULL);
	pipedes = lm_malloc(sizeof(int), 2 * info->plen, &info->head);
	if (pipedes == NULL)
		return (perror(info->shell), lm_flush(&info->head), NULL);
	while (i < info->plen)
	{
		info->pipebox[i] = &pipedes[2 * i];
		i++;
	}
	return (sb_assign_pipe(info));
}