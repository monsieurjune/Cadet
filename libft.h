/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:17:08 by tponutha          #+#    #+#             */
/*   Updated: 2023/05/28 16:43:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "listmem.h"
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# else
#  if BUFFER_SIZE <= 0 || BUFFER_SIZE > 0xfffffff
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1024
#  endif
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

/*      ft_gnl.c    */
char	*get_next_line(int fd, t_mem **head);

/*      ft_split_cmd.c    */
char	**ft_split(char const *s, char c, t_mem **head);

/*      ft_gnl_utils.c    */
size_t	ft_strclen(const char *str, char c);
char	*ft_strndup(const char *s0, size_t len, t_mem **head);
char	*ft_strcat(char *s0, const char *s1, const char *s2);

#endif