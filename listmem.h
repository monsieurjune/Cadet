/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:47:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 23:37:13 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTMEM_H
# define LISTMEM_H
# include <stdlib.h>

typedef struct s_linkmem
{
	void				*mem;
	struct s_linkmem	*next;
}	t_listmem;

void	*lm_malloc(size_t byte, size_t n, t_listmem **head);
void	lm_free(void *byte, t_listmem **head);
void	lm_flush(t_listmem **head);

#endif