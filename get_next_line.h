/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:45:33 by tponutha          #+#    #+#             */
/*   Updated: 2022/10/10 00:04:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# else
#  if BUFFER_SIZE <= 0 || BUFFER_SIZE > 0xfffffff
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1024
#  endif
# endif

char	*get_next_line(int fd);

size_t	ft_strclen(const char *str, char c);
char	*ft_strndup(const char *s0, size_t len);
char	*ft_strcat(char *s0, const char *s1, const char *s2);

#endif