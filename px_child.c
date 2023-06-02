/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 06:59:09 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/02 17:39:20 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	**sb_assign_pipe(int **pbox, int pipelen, t_pipex *info)
{
	int	i;
	
	i = 0;
	while (i < pipelen)
	{
		if (pipe(pbox[i]) == -1)
			break ;
		i++;
	}
	info->plen = pipelen;
	if (i == pipelen)
		return (pbox);
    i = i - 1;
	perror(info->shell);
	while (i >= 0)
	{
		px_close(pbox[i][0], info->shell);
		px_close(pbox[i][1], info->shell);
		i--;
	}
	return (NULL);
}

/* ALLOCATE PIPE
	- if error, will close every pipes before return NULL
*/

int	**px_allocate_pipe(t_pipex *info)
{
	int	**pbox;
	int	*pipedes;
	int	pipelen;
	int	i;

	pipelen = info->ac - 2 - (info->infile == 0);
	i = 0;
	pbox = lm_malloc(sizeof(int *), pipelen, &info->head);
	if (pbox == NULL)
		return (lm_flush(&info->head), perror(info->shell), NULL);
	pipedes = lm_malloc(sizeof(int), 2 * pipelen, &info->head);
	if (pipedes == NULL)
		return (lm_flush(&info->head), perror(info->shell), NULL);
	while (i < pipelen)
	{
		pbox[i] = &pipedes[2 * i];
		i++;
	}
	return (sb_assign_pipe(pbox, pipelen, info));
}