/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:10:49 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 23:11:30 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef SIZE_MAX
#  if __WORDSIZE == 64
#   define SIZE_MAX 18446744073709551615UL
#  else
#   define SIZE_MAX 4294967295U
#  endif
# endif

# ifndef INTMAX
#  define INTMAX 2147483647
# endif

# ifndef INTMIN
#  define INTMIN -2147483648
# endif

typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}	t_mem;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*		PART I		*/
void	*ft_memset(void *ptr, int c, size_t byte);
void	*ft_bzero(void *ptr, size_t byte);
void	*ft_memcpy(void *dst, const void *src, size_t byte);
void	*ft_memmove(void *dst, const void *src, size_t byte);
void	*ft_memchr(const void *ptr, int c, size_t byte);
int		ft_memcmp(const void *p1, const void *p2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strclen(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *find, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*		PART II	(heap)	*/
void	*ft_malloc(size_t byte, size_t size, t_list **head); //
void	*ft_calloc(size_t byte, size_t size, t_list **head); //
void	ft_free(void *mem, t_list **head); //
void	ft_flush(t_list **head); //
char	*ft_strdup(const char *src, t_list **head); //
char	*ft_strndup(const char *src, size_t len, t_list **head); //
char	*ft_strcdup(const char *src, char c, t_list **head); //
char	*ft_substr(char const *s, unsigned int start, size_t len, t_list **head); //
char	*ft_strjoin(char const *s1, char const *s2, t_list **head); //
char	*ft_strtrim(char const *s1, char const *set, t_list **head); //
char	**ft_split(char const *s, char c, t_list **head); //
char	*ft_itoa(int n, t_list **head); //
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char), t_list **head); //
void	ft_striteri(char *s, void (*f)(unsigned int, char*)); //

/*		PART II (fd)*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*		BONUS		*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newc);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newc);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
