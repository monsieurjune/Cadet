/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astable.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:47:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:25:01 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTABLE_H
# define ASTABLE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}	t_mem;

typedef struct s_data
{
	struct s_mem	*head;
	int8_t			table[OPEN_MAX + 1];
}	t_data;

// astable.c
t_data	as_init(void);
int		as_flush_data(t_data *data);
void	as_error_exit(t_data *data, const char *err_str);
void	*ft_memset(void *ptr, int c, size_t byte);

// as_file.c
int		as_open(t_data data, const char *path, int flag);
int		as_close(t_data data, int fd);
void	as_close_all(t_data data);

// as_malloc.c
void	*as_malloc(size_t byte, size_t n, t_mem **head);
void	*as_calloc(size_t byte, size_t n, t_mem **head);

// as_free.c
void	as_free(void *byte, t_mem **head);
void	as_flush_mem(t_mem **head);

// as_utils.c

#endif