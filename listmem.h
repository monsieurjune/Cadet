/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minerva <minerva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:47:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/10 22:09:30 by minerva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTMEM_H
# define LISTMEM_H
# include <stdlib.h>
# include <stdint.h>

typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}	t_mem;

// listmem.c
void	*lm_malloc(size_t byte, size_t n, t_mem **head);
void	*lm_calloc(size_t byte, size_t n, t_mem **head);

// listfree.c
void	lm_free(void *byte, t_mem **head);
void	lm_flush(t_mem **head);

#endif