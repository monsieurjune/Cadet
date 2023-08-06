/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:17:08 by tponutha          #+#    #+#             */
/*   Updated: 2023/08/06 22:59:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# ifdef __linux
#  include <stdint.h>
# endif

typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}	t_mem;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
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
char	**ft_split_cmd(char const *s, char c, t_mem **head);

/*		ft_strnstr.c	*/
char	*ft_strnstr(const char *str, const char *find, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnchr(const char *str, size_t n, int c);

/*      ft_gnl_utils.c    */
size_t	ft_strclen(const char *str, char c);
char	*ft_strndup(const char *s0, size_t len, t_mem **head);
char	*ft_strcat(char *s0, const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2, t_mem **head);
char	*ft_threemany(char const *s1, char const *s2, int n, t_mem **head);

// listmem.c
void	*lm_malloc(size_t byte, size_t n, t_mem **head);
void	*lm_calloc(size_t byte, size_t n, t_mem **head);

// listfree.c
void	lm_free(void *byte, t_mem **head);
void	lm_flush(t_mem **head);

#endif