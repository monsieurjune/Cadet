/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 03:56:45 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/09 04:13:28 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	if (ac != 5)
		return (EXIT_SUCCESS);
	px_pipex_first_init(&info, ac, av, env);
	px_pipex_second_init(&info, 1);
	px_calling_child(&info, -1);
	return (0);
}
