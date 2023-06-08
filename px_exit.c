/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:43:28 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/08 10:28:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
0 : success
1: file permission denied
126: cmd permission denied
127: no such file or directory
*/

void	px_exit(void)
{
	if (errno == 0)
		exit(0);
	if (errno == )
}